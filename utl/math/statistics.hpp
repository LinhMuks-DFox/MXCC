//
// Created by Mux on 2021/11/08.
//

#ifndef MXC_STATISTICS_HPP
#define MXC_STATISTICS_HPP

#include "_math_config.h"
#include

namespace MXC::Math {
    [[deprecated ("Unimplemented yet.")]]
    template<class T = float64>
    static inline T mean(std::array<T> arr) noexcept {
        if (arr.empty()) return (T) nan();
        float64 ret = 0;
        for (auto i = arr.begin(); i != arr.end(); ++i, ret += *i;);
        return ret / arr.size();
    }
}
#endif //MXC_STATISTICS_HPP
