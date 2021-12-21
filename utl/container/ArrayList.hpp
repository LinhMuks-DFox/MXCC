#pragma once
#ifndef MXC_ARRAY_LIST
#define MXC_ARRAY_LIST
#include "IList.hpp"
namespace MXC::Container {

    template<class T>
    class [[deprecated("Unimplemented yet")]] ArrayList : public IList {
    private:
        T *_arr = nullptr;
        uint64 size = 0;
        bool _read_only = true;

    public:
        ~ArrayList() {
            delete[] _arr;
        }
    };
}// namespace MXC::Container

#endif// MXC_ARRAY_LIST