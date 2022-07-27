//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"
#include "utl/String/StringUtl.hpp"
using namespace MXC;
using namespace std;

auto print_vector() -> double {
    return 0.0;
}

int main() {
    std::vector<gl_str> des;
    MXC::StringUtl::StringSplitter<>::Split("this,is a test of split"s, " ,", des);
    for (const auto& str: des) {
        std::cout << str << "|";
    }
    return 0;
}
