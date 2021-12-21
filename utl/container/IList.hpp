#pragma once
#ifndef MXC_I_LIST
#define MXC_I_LIST
#include "../_builtin_exception.hpp"
#include "../_object.hpp"
namespace MXC::Container {

    template<class Dtype>
    class IList : public object {
    protected:
        uint64 _size = 0;

    public:
        IList() {}
        ~IList() {}

    public:
        virtual inline Dtype &operator[](uint64 idx){} = 0;

        virtual inline const Dtype &ai_index(uint64 idx) const {} = 0;

        virtual inline void assign(uint64 idx, Dtype &obj){} = 0;

        virtual inline void assign(uint64 idx, Dtype &&obj){} = 0;
    };
}// namespace MXC::Container

#endif// MXC_I_LIST