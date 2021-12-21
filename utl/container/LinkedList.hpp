//
// Created by Mux on 2021/11/6.
//

#ifndef MXC_LIST_HPP
#define MXC_LIST_HPP

#include "IList.hpp"

namespace MXC::Container {

    template<typename T>
    class [[deprecated("Unimplemented yet.")]] LinkedList : public object {
    private:
        struct node {
            T *ele;
            node *next;

            ~node() {
                delete ele;
            }
        } _dummy_head = {nullptr, nullptr};

        uint64 _size{0};
        bool _readonly{false};

    private:
        void clear() { delete_nodes(_dummy_head.next); }

        void delete_nodes(node * node) {
            if (!node)// nullptr: (void*) 0x00;
                return;
            delete_nodes(node.next);
            delete node;
        }

        node *find_node(node * p, const T &i) {// find node.T == i;
            if (*p->ele == i) {
                return p;
            }
            if (!p->next)
                return nullptr;
            return find_node(p->next, i);
        }

    public:
        LinkedList() : object("MXC::Container::LinkedList", 1) {}

        LinkedList(const LinkedList &) = delete;

        LinkedList &operator=(const LinkedList &) = delete;

        ~LinkedList() { clear(); }

        void insert(uint64 idx, const T &e) = 0;

        void insert(uint64 idx, T && e) = 0;

        void append(const T &e) = 0;

        void append(T && e) = 0;

        void remove(uint64 idx) = 0;

        void assign(uint64 idx, const T &e) = 0;

        void assign(uint64 idx, T && e) = 0;

        void get() = 0;
    };
}// namespace MXC::Container
#endif//MXC_LIST_HPP
