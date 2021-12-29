#pragma once
#ifndef MXC_ARRAY_LIST
#define MXC_ARRAY_LIST

#include "IList.hpp"

#define VECTOR_OBJECT_INIT object("MXC::Container::Vector", 2)
#define INDEX_RANGE_CHECK   \
    if (idx > _size)        \
        throw Exp::InvalidOperation("index out of range.");

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

        Vector(Vector &&v) noexcept: _arr(v._arr), _size(v._arr),
                                     _read_only(v._read_only) {
            v._release_source();
        }

    public:
        inline const T &at_index(uint64 idx) const override {
            INDEX_RANGE_CHECK
            return _arr[idx];
        }

        inline int assign(uint64 idx, T &obj) override {
            INDEX_RANGE_CHECK
            _arr[idx] = std::move(obj);
        }

        inline int assign(uint64 idx, T &&obj) override {
            INDEX_RANGE_CHECK
            _arr[idx] = std::move(obj);
        }

        inline int insert(uint64 idx, const T &obj) override {
            INDEX_RANGE_CHECK
            return 0;
        }

        inline int insert(uint64 idx, T &&obj) override {
            INDEX_RANGE_CHECK
        }

        inline T &&remove_at(uint64 idx)
        override {
            INDEX_RANGE_CHECK
        }

        [[nodiscard]] inline size_t size() const override {
            return this->size;
        }
    };
}// namespace MXC::Container
#undef VECTOR_OBJECT_INIT
#endif// MXC_ARRAY_LIST