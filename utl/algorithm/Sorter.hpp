//
// Created by Mux on 2022/1/19.
//

#ifndef MXC_SORTER_HPP
#define MXC_SORTER_HPP

#include "_sorter_base.hpp"

namespace MXC::Algorithm {
    template<typename T>
        requires std::three_way_comparable<T> || CSortable<T>
    class QuickSorter : public Sorter<T> {
    public:
        QuickSorter(std::iterator<T> begin, std::iterator<T> end)
            : Sorter<T>("MXC::Algorithm::QuickSorter", 2) { }

    public:
        void sort() final { }
    }
}// namespace MXC::Algorithm
#endif//MXC_SORTER_HPP
