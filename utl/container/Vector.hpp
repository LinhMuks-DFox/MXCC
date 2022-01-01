#pragma once
#ifndef MXC_ARRAY_LIST
#define MXC_ARRAY_LIST

#include "IList.hpp"

#define VECTOR_OBJECT_INIT object("MXC::Container::Vector", 2), IList<T>()
#define INDEX_RANGE_CHECK   \
    if (idx > _size)        \
        throw Exp::InvalidOperation("index out of range.");

namespace MXC::Container {

    template<class T, const size_t default_size = 1024>
    class Vector : public virtual IList<T> {
    private:
        T *_arr = nullptr;
        bool _read_only = true;
        int64 _size = 0, _capacity = 0;
    public:
        ~Vector() {
            clean();
            delete[](char *) _arr;
            _arr = nullptr;
            _size = 0;
        }

    public:
        Vector() : VECTOR_OBJECT_INIT {
            _arr = (T *) new char[sizeof(T) * default_size];
            _size = 0;
            _capacity = default_size;
        }

        explicit Vector(int64 obj_cnt) : VECTOR_OBJECT_INIT {
            _arr = (T *) new char[sizeof(T) * obj_cnt];
            _capacity = obj_cnt;
            _size = 0;
        }

        Vector(std::initializer_list<T> list) : VECTOR_OBJECT_INIT {
            _arr = (T *) new char[sizeof(T) * list.size()];
            _capacity = list.size();
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
                                     _read_only(v._read_only), VECTOR_OBJECT_INIT {
            v._release_source();
        }

    private:
        void _resize(int64 new_capacity) {
            auto *t = (T *) new char[sizeof(T) * new_capacity];
            for (auto i = 0; i < _size; ++i)
                t[i] = _arr[i];
            delete[] (char *) _arr;
            _arr = t;
        }

        void _check_capacity() {
            if (_size != _capacity / 4 || _capacity / 2 == 0) return;
            _resize(_capacity / 2);
        }

        void _release_source() {
            _arr = nullptr;
            _size = 0;
            _read_only = true;
        }


    public: /* overriding MXC::Container::IList<T> */
        inline const T &at_index(int64 idx) const override {
            INDEX_RANGE_CHECK
            return _arr[idx];
        }

        inline void assign(int64 idx, T &obj) override {
            INDEX_RANGE_CHECK
            _arr[idx] = std::move(obj);
        }

        inline void assign(int64 idx, T &&obj) override {
            INDEX_RANGE_CHECK
            _arr[idx] = std::move(obj);
        }

        inline void insert(int64 idx, T &obj) override {
            INDEX_RANGE_CHECK
            if (_size == _capacity)
                _resize(2 * _capacity);
            for (auto i = _size - 1; i >= idx; i--)
                _arr[i + 1] = _arr[i];
            _arr[idx] = std::move(obj);
            _size++;
        }

        inline void insert(int64 idx, T &&obj) override {
            INDEX_RANGE_CHECK
            if (_size == _capacity)
                _resize(2 * _capacity);
            for (auto i = _size - 1; i >= idx; i--)
                _arr[i + 1] = _arr[i];
            _arr[idx] = std::move(obj);
            _size++;
        }

        inline T &&remove_at(int64 idx) override {
            INDEX_RANGE_CHECK
            auto ret = std::move(_arr[idx]);
            for (auto i = idx + 1; i < _size; i++)
                _arr[i - 1] = _arr[i];
            _size--;
            _check_capacity();

            return std::move(ret);
        }

        [[nodiscard]] inline int64 size() const override {
            return this->_size;
        }

    public: /* not override Method */

        void clean() {
            for (auto i = 0; i < _size; ++i) {
                _arr[i].~T();
            }
            _size = 0;
        }

        void init_all() {
            for (auto i = _size; i < _capacity; ++i) {
                _arr[i].T();
            }
            _size = _capacity;
        }

        [[nodiscard]] inline int64 capacity() const {
            return this->_capacity;
        }

        [[nodiscard]] inline bool empty() const {
            return _size == 0;
        }

        inline void reserve(int64 size) {
            if (size > _capacity)
                return;
            _resize(size);
        }

        inline void append(T &obj) {
            insert(_size, std::move(obj));
        }

        inline void append(T &&obj) {
            insert(std::move(obj));
        }

        inline void add_first(T &obj) {
            insert(0, std::move(obj));
        }

        inline void add_first(T &&obj) {
            insert(0, std::move(obj));
        }

        inline void append(std::initializer_list<T> list) {
            if (_capacity - _size <= list.size())
                _resize(_capacity + 2 * list.size());
            if (empty()) {
                reserve(list.size());
                std::copy(std::begin(list), std::end(list), _arr);
                return;
            }
            std::copy(std::begin(list), std::end(list), _arr + _size);
            _size += list.size();
        }
    };
}// namespace MXC::Container
#undef VECTOR_OBJECT_INIT
#endif// MXC_ARRAY_LIST