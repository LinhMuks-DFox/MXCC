//
// Created by Mux on 2022/1/22.
//

#ifndef MXC__SORTER_BASE_HPP
#define MXC__SORTER_BASE_HPP

#include "../_object.hpp"
#include "../_builtin_exception.hpp"

namespace MXC::Algorithm {
    template<typename T>
    concept CSortable = requires(const T &a, const T &b) {
        { a <= b } -> std::convertible_to<bool>;
        { a < b } -> std::convertible_to<bool>;
        { a > b } -> std::convertible_to<bool>;
        { a >= b } -> std::convertible_to<bool>;
    };

    template<std::three_way_comparable T>
    class Sorter : public object {
        virtual sort() = 0;
    };
}
#endif //MXC__SORTER_BASE_HPP
