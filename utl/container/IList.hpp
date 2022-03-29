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
        IList(gl_str t_name, uint64 gen) : object(t_name, gen) {}
    public:
        virtual inline const T &at_index(int64 idx) const = 0;

        virtual inline void assign(int64 idx, T &obj) = 0;

        virtual inline void assign(int64 idx, T &&obj) = 0;

        virtual inline void insert(int64 idx, T &obj) = 0;

        virtual inline void insert(int64 idx, T &&obj) = 0;

        virtual inline T &&remove_at(int64 idx) = 0;

        [[nodiscard]] virtual inline int64 size() const = 0;
    };
}// namespace MXC::Container

#endif// MXC_I_LIST