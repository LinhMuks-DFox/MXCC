#pragma once
#ifndef MXC_I_LIST
#define MXC_I_LIST
#include "../_builtin_exception.hpp"
#include "../_object.hpp"
namespace MXC::Container {

    template<class T>
    class IList : public virtual object {
    protected:
        IList() : object("MXC::Container::IList", 1) {}
    public:
        virtual inline const T &at_index(uint64 idx) const = 0;

        virtual inline void assign(uint64 idx, T &obj) = 0;

        virtual inline void assign(uint64 idx, T &&obj) = 0;

        virtual inline int insert(uint64 idx, const T& obj) =0;

        virtual inline int insert(uint64 idx, T&& obj) =0;

        virtual inline T&& remove_at(uint64) = 0;

        [[nodiscard]] virtual inline size_t size() const = 0;
    };
}// namespace MXC::Container

#endif// MXC_I_LIST