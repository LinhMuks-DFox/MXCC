//
// Created by Mux on 2021/10/27.
//

#ifndef MXC_MATH_HPP
#define MXC_MATH_HPP

#include "../_config.hpp"
#include <cmath>

namespace MXC::Math {


#pragma region logarithm


    [[deprecated("Untested yet.")]] static inline float64
    log_base(const float64 &value, const float64 &base) {
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
        return std::log(base) / std::log(value);
    }

    static inline float64 quick_mul(const float64 &x, const int64 &N) noexcept {
        float64 ans = 1.0;
        auto n = N;
        auto x_contribute = x;
        while (n > 0) {
            if (n % 2) {
                ans *= x_contribute;
            }
            x_contribute *= x_contribute;
            n /= 2;
        }
        return ans;
    }

    static inline float64 pow(const float64 &x, const int32 &n) noexcept {
        int64 N = n;
        return N >= 0 ? quick_mul(x, N) : 1.0 / quick_mul(x, -N);
    }

    // From: https://www.zhihu.com/question/35122102
    template<typename T>
    struct i_sqrt_traits {
        static_assert(std::is_unsigned<T>::value,
                      "Generic i_sqrt only on unsigned types");

        static size_t bitCount(const T &n) {
            T a(n);
            size_t count = 0;
            while (a > 0) {
                a >>= 2;
                count += 2;
            }
            return count;
        }

        static uint8_t extract_tow_bits_at(const T &n, size_t i) {
            return static_cast<uint8_t>((n >> i) & 3);
        }
    };

    template<typename T>
    T i_sqrt(const T &n) {
        T remainder{}, root{};
        auto bitCount = i_sqrt_traits<T>::bitCount(n);
        for (size_t i = bitCount; i > 0;) {
            i -= 2;
            root <<= 1;
            ++root;
            remainder <<= 2;
            remainder |= i_sqrt_traits<T>::extract_tow_bits_at(n, i);
            if (root <= remainder) {
                remainder -= root;
                ++root;
            } else
                --root;
        }

        return root >>= 1;
    }

    bool is_prime(const uint64 &num) {
        if (num < 1) return false;
        if (num == 2) return true;
        auto limit = i_sqrt<uint64>(num);
        for (auto i = 2; i < limit; ++i) {
            if (num % i == 0) { return false; }
        }
        return true;
    }

#pragma endregion
}// namespace MXC::Math
#endif//MXC_MATH_HPP
