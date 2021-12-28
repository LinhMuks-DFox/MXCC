#pragma once
#ifndef MXC_ARRAY_LIST
#define MXC_ARRAY_LIST

#include "IList.hpp"

#define VECTOR_OBJECT_INIT object("MXC::Container::Vector", 2)
namespace MXC::Container {

    template<class T, size_t default_size = 1024>
    class Vector : public IList<T> {
    private:
        T *_arr = nullptr;
        bool _read_only = true;
        size_t _size = 0;
    public:
        ~Vector() {
            delete[](char *) *_arr;
            _arr = nullptr;
            _size = 0;
        }

    private:
        void _release_source() {
            _arr = nullptr;
            _size = 0;
            _read_only = true;
        }

    public:
        explicit Vector() : VECTOR_OBJECT_INIT {
            _arr = (T *) new char[sizeof(T) * default_size];
            _size = default_size;
        }

        explicit Vector(size_t obj_cnt) : VECTOR_OBJECT_INIT {
            _arr = (T *) new char[sizeof(T) * obj_cnt];
            _size = obj_cnt;
        }

        Vector(std::initializer_list<T> list) : VECTOR_OBJECT_INIT {
            _arr = (T *) new char[sizeof(T) * list.size()];
            _size = list.size();
            std::copy(list.begin(), list.end(), _arr);
        }

        Vector(const Vector<T> &) = delete;

        Vector &operator=(const Vector<T> &) = delete;

        Vector &operator=(Vector &&v) noexcept {
            if (_arr != nullptr)
                delete[] (char *) _arr;
            _size = v._size;
            _arr = v._arr;
            v._release_source();
        }

        Vector(Vector &&v) noexcept: _arr(v._arr), _size(v._arr), _read_only(v._read_only) {
            v._release_source();
        }

    public:
        inline const T &at_index(uint64 idx) const {}

        inline void assign(uint64 idx, T &obj) {}

        inline void assign(uint64 idx, T &&obj) {}

        inline int insert(uint64 idx, const T &obj) {}

        inline int insert(uint64 idx, T &&obj) {}

        inline T &&remove_at(uint64) {}

        [[nodiscard]] inline size_t size() const override {
            return this->size;
        }
    };
}// namespace MXC::Container
#undef VECTOR_OBJECT_INIT
#endif// MXC_ARRAY_LIST