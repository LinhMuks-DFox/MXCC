//
// Created by Mux on 2021/10/25.
//

#ifndef MXC__OBJECT_CPP
#define MXC__OBJECT_CPP

// ensure cpp is usable
#ifndef __cplusplus
#error "C++ complier required."
#endif

// ensure cpp std14up is usable
#if __cplusplus < 201403L
#error "At least C++14 or higher required"
#endif

#include <string>
#include <queue>
#include <algorithm>
#include <exception>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>
#include <bitset>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <memory>
#include <iomanip>
#include <ctime>
#include <array>
#include <unordered_map>
#include <list>
#include <map>
#include <vector>

#pragma region OS_MACRO

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)// only windows64 defined _WIN64,
#endif

#if defined(uinix) || defined(__unix__) || defined(__unix) // for unix/linux/macos
#endif

#if defined(__APPLE__) || defined(__MACH__) // For mac-os
#endif

#if defined(__ANDROID__) // for android
#endif

#if defined(__linux) || defined(linux) || defined(__linux) // for linux
#endif

#pragma endregion

namespace MXC {
    typedef std::string gl_str; // global basic string. now is std::string.

    typedef std::int8_t int8;
    typedef std::int16_t int16;
    typedef std::int32_t int32;
    typedef std::int32_t int64;

    typedef std::uint8_t uint8;
    typedef std::uint16_t uint16;
    typedef std::uint32_t uint32;
    typedef std::uint64_t uint64;
    typedef std::uint64_t hash_code;
    typedef float float32;
    typedef double float64;

    typedef std::uint64_t memory_length;
    using std::cout;
    using std::endl;

    template<class T, memory_length length = 1, bool help_init = false>
    static inline T *memory_static_allocate() noexcept {
        T *ret = (T *) new char[sizeof(T) * length];
        if (help_init) for (memory_length p = 0; p < length; ++p) new(ret + p) T(); // placement new;
        return ret;
    }

    template<class Ty, bool help_finalize = false, memory_length length = 0>
    static inline void static_free_memory(Ty **ptr) noexcept {
        if (help_finalize) for (memory_length p = 0; p < length; ++p) (*ptr)[p].~Ty(); // placement delete;
        delete[] (char *) *ptr;
        *ptr = nullptr;
    }

    inline gl_str to_string(bool boolean_expression) noexcept {
        return boolean_expression ? "True" : "False";
    }
}
#if __cplusplus >= 202002L
#include <format>
namespace MXC{
    using std::format;
}
#endif //__cplusplus
#endif // MXC__CONFIG