//
// Created by Mux on 2021/10/25.
//

#ifndef MXCC__OBJECT_CPP
#define MXCC__OBJECT_CPP

#include <string>
#include <exception>
#include <cstdint>
#include <cstdlib>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>

namespace MXCC {
    typedef std::string cv_str_t; // current version string

    typedef std::int8_t int8;
    typedef std::int16_t int16;
    typedef std::int32_t int32;
    typedef std::int32_t int64;

    typedef std::uint8_t uint8;
    typedef std::uint16_t uint16;
    typedef std::uint32_t uint32;
    typedef std::uint32_t uint64;
}

#if __cplusplus >= 202002L
#include <format>
namespace MXCC{
    using std::format;
}
#endif //MXCC__OBJECT_CPP
