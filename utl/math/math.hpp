//
// Created by Mux on 2021/10/27.
//

#ifndef MXC_MATH_HPP
#define MXC_MATH_HPP

#include "../_config.hpp"
#include <cmath>

namespace MXC::Math {
#pragma region constant
    static const float64 EPSILON(1e-8);

    static const float64 E(2.71828182845904523536L); // exp

    static const float64 PI(3.14159265358979323846L); // pi

    static const float64 PI_2(1.57079632679489661923L); // pi / 2

    static const float64 PI_4(0.78539816339744830961L); // pi / 4

    static const float64 SQRT_2(1.41421356237309504880L); // sqrt(2)

    static const float64 SQRT_1_2(0.70710678118654752440L); // 1 / sqrt(2)

    static const float64 LOG2_E(1.44269504088896340736L); // log2(E)
#pragma endregion

#pragma region IEEE754 Special Values

    static inline float32 infinity() {
        const union {
            uint32 i;
            float32 y;
        } _f{0x7f800000UL};
        return _f.y;
    }

    static inline float32 nan() {
        const union {
            uint32 i;
            float32 y;
        } _f{0x7fc00000UL};
        return _f.y;
    }

    static inline float32 poz_zero() {
        const union {
            uint32 i;
            float32 y;
        } _f{0x00000000UL};
        return _f.y;
    }

    static inline float32 neg_zero() {
        const union {
            uint32 i;
            float32 y;
        } _f{0x80000000UL};
        return _f.y;
    }

    static inline float32 neg_infinity() {
        const union {
            uint32 i;
            float32 y;
        } _f{0xff800000ul};
        return _f.y;
    }

#pragma endregion

    static inline bool float64_eq(const float64 &a, const float64 &b) noexcept {
        return (a - b) < EPSILON;
    }

#pragma region logarithm

    static inline float64 log_base(float64 value, float64 base) {
        /*!
         * log function in MXC return log value same as std::log()
         * when value eq 1, return 0.0
         * when value eq 0, return negative infinity
         * when value less then 0, return NaN, a.k.a Not a number.
         * else, return log_{base} (value): log(81, 3) -> 4
         */
        if (float64_eq(value, 1.0))
            return poz_zero();
        if (float64_eq(value, 0.0))
            return neg_infinity();
        if (value < 0.0)
            return nan();

    }

    static inline float64 log_2(float64 v) {
        if (float64_eq(v, E))
            return LOG2_E;
        return log_base(v, 2.);
    }

    static inline float64 log_exp(float64 v) {
        return log_base(v, E);
    }

    static inline float64 log_n() {}

    static inline float64 log10() {}

#pragma endregion
}
#endif //MXC_MATH_HPP
