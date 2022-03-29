//
// Created by Mux on 2022/3/29.
//

#ifndef MXC_JUMPLIST_HPP
#define MXC_JUMPLIST_HPP
#include "IList.hpp"

namespace MXC::Container{
    template<typename T>
    class JumpList : public IList<T> {
        JumpList() : IList<T>("MXC::Container::JumpList", 2){}
    };
}
#endif //MXC_JUMPLIST_HPP
