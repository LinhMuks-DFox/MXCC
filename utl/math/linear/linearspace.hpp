#ifndef MXC_MATH_LINEAR_LINEAR_SPACE
#define MXC_MATH_LINEAR_LINEAR_SPACE

#include "../_math_config.h"

namespace MXC::Math::Linear {

    template<typename T>
    void linear_space(std::vector<double> &linear_spaced, T start_in, T end_in,
                      int num_in) {
        linear_spaced.clear();
        auto start = static_cast<double>(start_in);
        auto end = static_cast<double>(end_in);
        auto num = static_cast<double>(num_in);
        if (num == 0) { return; }
        if (num == 1) {
            linear_spaced.push_back(start);
            return;
        }
        double delta = (end - start) / (num - 1);
        for (int i = 0; i < num - 1; ++i) { linear_spaced.push_back(start + delta * i); }
        linear_spaced.push_back(end);
        // I want to ensure that start and end
        // are exactly the same as the input
    }
}// namespace MXC::Math::Linear
#endif// MXC_MATH_LINEAR_LINEAR_SPACE