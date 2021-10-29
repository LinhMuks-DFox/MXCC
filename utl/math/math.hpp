//
// Created by Mux on 2021/10/27.
//

#ifndef MXCC_MATH_HPP
#define MXCC_MATH_HPP

#include "../_config.hpp"
// to check if compiler using IEEE-754
#if __DBL_DIG__ != 15 || __DBL_MANT_DIG__ != 53 \
    || __DBL_MAX_10_EXP__ != 308 || __DBL_MAX_EXP__ != 1024 \
    || __DBL_MIN_10_EXP__ != -307 || __DBL_MIN_EXP__ != -1021
#error "Requires IEEE 754 floating point"
#endif
namespace MXCC::math {
    static inline float32 inffnity() {
        const union {
            uint32 i;
            float32 y;
        } __f{0x7f800000UL};
        return __f.y;
    }

    static inline float32 nan() {
        const union {
            uint32 i;
            float32 y;
        } __f{0x7fc00000UL};
        return __f.y;
    }

    static inline float32 p_zero() {
        const union {
            uint32 i;
            float32 y;
        } __f{0x00000000UL};
        return __f.y;
    }

    static inline float32 n_zero() {
        const union {
            uint32 i;
            float32 y;
        } __f{0x80000000UL};
        return __f.y;
    }

    static inline float32 n_inff() {
        const union {
            uint32 i;
            float32 y;
        } __f{0xff800000ul};
        return __f.y;
    }
}
#endif //MXCC_MATH_HPP
