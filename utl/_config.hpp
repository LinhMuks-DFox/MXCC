//
// Created by Mux on 2021/10/25.
//

#ifndef MXC__OBJECT_CPP
#define MXC__OBJECT_CPP

// ensure cpp is usable
#ifndef __cplusplus
#error "C++ complier required."
#endif

// ensure cpp std20up is usable
#if __cplusplus < 202002L
#error "At least C++20 or higher required"
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <compare>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma region OS_MACRO

#if defined(_WIN32) || defined(_WIN64) ||                                     \
        defined(__CYGWIN__)// only windows64 defined _WIN64,
#include "windows.h"
#endif

#if defined(uinix) || defined(__unix__) ||                                    \
        defined(__unix)// for unix/linux/macos
#endif

#if defined(__APPLE__) || defined(__MACH__)// For mac-os
#endif

#if defined(__ANDROID__)// for android
#endif

#if defined(__linux) || defined(linux) || defined(__linux)// for linux
#endif

#pragma endregion
namespace MXC {
    using std::literals::string_literals::operator""s;
    using int8 = std::int8_t;
    using int16 = std::int16_t;
    using int32 = std::int32_t;
    using int64 = std::int32_t;

    using uint8 = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;
    using hash_code = std::uint64_t;
    using float32 = float;
    using dfloat = double;

    using memory_length = std::uint64_t;
    using std::cout;
    using std::endl;
    using gl_str = std::string;// global basic string. now is std::string.


    template<class T, memory_length length = 1, bool help_init = false>
    static constexpr inline T *memory_static_allocate() noexcept {
        T *ret = (T *) new char[sizeof(T) * length];
        if (help_init)
            for (memory_length p = 0; p < length; ++p)
                new (ret + p) T();// placement new;
        return ret;
    }

    template<class Ty, bool help_finalize = false, memory_length length = 0>
    static constexpr inline void static_free_memory(Ty **ptr) noexcept {
        if (help_finalize)
            for (memory_length p = 0; p < length; ++p)
                (*ptr)[p].~Ty();// placement delete;
        delete[] (char *) *ptr;
        *ptr = nullptr;
    }

    inline gl_str to_string(bool boolean_expression) noexcept {
        return boolean_expression ? "True"s : "False"s;
    }
}// namespace MXC
#if __cplusplus >= 202002L
#endif//__cplusplus
#endif// MXC__CONFIG