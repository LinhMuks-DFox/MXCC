#include "../../Vector.hpp"
#include <iostream>

using namespace std;

class Foo {
private:
    int *arr = nullptr;

public:
    friend inline ostream &operator<<(ostream &ost, const Foo &f) {
        return ost;
    }
};

template<class T = int>
void show_vector(const MXC::Container::Vector<T> &v) {
    cout << "Vector size:" << v.size() << endl;
    cout << "Vector capacity:" << v.capacity() << endl;
    for (auto i = 0; i < v.size(); ++i) cout << v.at_index(i) << ", ";
}


void unit_test1() {
    using MXC::Container::Vector;
    Vector<int> v(40);
    for (auto i = 0; i < 10; ++i) v.insert(i, i);
    show_vector(v);

    auto t = v.remove_at(3);
    cout << endl << t << endl;

    show_vector(v);
}

void unit_test2() {
    using MXC::Container::Vector;
    Vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    show_vector(v);
}

int main() {
    unit_test2();
    return 0;
}
