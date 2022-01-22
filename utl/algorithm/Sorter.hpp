//
// Created by Mux on 2022/1/19.
//

#ifndef MXC_SORTER_HPP
#define MXC_SORTER_HPP

#include "_sorter_base.hpp"

namespace MXC::Algorithm {
    template<typename T>
    requires std::three_way_comparable<T>
    class QuickSorter : public Sorter{
    }
}
#endif //MXC_SORTER_HPP
