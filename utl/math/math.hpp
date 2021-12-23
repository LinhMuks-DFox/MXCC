//
// Created by Mux on 2021/10/27.
//

#ifndef MXC_MATH_HPP
#define MXC_MATH_HPP

#include "../_config.hpp"
#include <cmath>

namespace MXC::Math {


#pragma region logarithm

    [[deprecated("Unimplemented yet.")]] static inline float64
    log_base(float64 value, float64 base) {
        /*!
         * log function in MXC return log value same as std::log()
         * when value eq 1, return 0.0
         * when value eq 0, return negative infinity
         * when value less then 0, return NaN, a.k.a Not a number.
         * else, return log_{base} (value): log(81, 3) -> 4
         */
        if (float64_eq(value, 1.0)) return poz_zero();
        if (float64_eq(value, 0.0)) return neg_infinity();
        if (value < 0.0) return nan();
        // TODO: implement log_base.(logarithm of x base b = log(x)/log(b))
    }

    [[deprecated("Unimplemented yet.")]] static inline float64
    log_2(float64 v) {
        if (float64_eq(v, E)) return LOG2_E;
        return log_base(v, 2.);
    }

    [[deprecated("Unimplemented yet.")]] static inline float64
    log_exp(float64 v) {
        return log_base(v, E);
    }

    [[deprecated("Unimplemented yet.")]] static inline float64 log_n() {}

    [[deprecated("Unimplemented yet.")]] static inline float64 log10() {}

#pragma endregion
}// namespace MXC::Math
#endif//MXC_MATH_HPP
