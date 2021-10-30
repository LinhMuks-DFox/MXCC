#ifndef MXC__MATH_CONFIG_H
#define MXC__MATH_CONFIG_H
#include "../_config.hpp"
// to check if compiler using IEEE-754
#if __DBL_DIG__ != 15 || __DBL_MANT_DIG__ != 53 \
    || __DBL_MAX_10_EXP__ != 308 || __DBL_MAX_EXP__ != 1024 \
    || __DBL_MIN_10_EXP__ != -307 || __DBL_MIN_EXP__ != -1021
#error "Requires IEEE 754 floating point"
#endif
#endif //MXC__MATH_CONFIG_H
