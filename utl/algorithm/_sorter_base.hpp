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

    template<typename T> requires std::three_way_comparable<T> || CSortable<T>
    class Sorter : public object {
    protected:
        Sorter(gl_str &name, uint32 gen) : object(name, gen) {

        }

    public:
        Sorter() : object("MXC::Algorithm::Sorter", 1) {

        }

        virtual void sort() = 0;

        virtual void swap(T &i, T &j) = 0;
    };
}
#endif //MXC__SORTER_BASE_HPP
