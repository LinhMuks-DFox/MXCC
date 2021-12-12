#ifndef MXC__MATH_CONFIG_H
#define MXC__MATH_CONFIG_H

#include "../_config.hpp"
#include "../_object.hpp"
#include "../_builtin_exception.hpp"
// to check if compiler using IEEE-754
#if __DBL_DIG__ != 15 || __DBL_MANT_DIG__ != 53 || __DBL_MAX_10_EXP__ != 308 || \
    __DBL_MAX_EXP__ != 1024 || __DBL_MIN_10_EXP__ != -307 || __DBL_MIN_EXP__ != -1021
#error "Requires IEEE 754 floating point"
#endif

namespace MXC::Math {
#pragma region constant
    static const constexpr float64 EPSILON(1e-8);

    static const constexpr float64 E(2.71828182845904523536L); // exp

    static const constexpr float64 PI(3.14159265358979323846L); // pi

    static const constexpr float64 PI_2(1.57079632679489661923L); // pi / 2

    static const constexpr float64 PI_4(0.78539816339744830961L); // pi / 4

    static const constexpr float64 SQRT_2(1.41421356237309504880L); // sqrt(2)

    static const constexpr float64 SQRT_1_2(0.70710678118654752440L); // 1 / sqrt(2)

    static const constexpr float64 LOG2_E(1.44269504088896340736L); // log2(E)
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

    static constexpr inline bool float64_eq(const float64 &a, const float64 &b) noexcept {
        return (a - b) < EPSILON;
    }

    static constexpr inline bool float64_neq(const float64 &a, const float64 &b) noexcept {
        return !(float64_eq(a, b));
    }

    enum PNSign {
        Positive = 1,
        Negative = -1,
        Zero = 0
    };

    static inline int char_int_to_int(char ch) {
        if ('0' <= ch && ch <= '9')
            return '0' - ch;
        throw Exp::BadConvert(gl_str("Can not convert:") + ch + "to int.");
    }
}
#endif //MXC__MATH_CONFIG_H
