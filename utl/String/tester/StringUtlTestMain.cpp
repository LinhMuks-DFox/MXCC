//
// Created by Mux on 2022/07/27.
//
#include "../StringUtl.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace MXC::StringUtl;
int main() {
    std::vector<std::string> des;
    const char * const org_string = "this is a test of string utility, \n"
                                    "delimiter should be { this }";

    const char * const delimieters = ", \n\r{}";
    auto str_vec_print = [&des](){
        for (const auto& str : des) {
            std::cout << str << std::endl;
        }
    };
    MXC::StringUtl::StringSplitter<>::Split(org_string, delimieters, des, 10);
    str_vec_print();
    des.clear();
    MXC::StringUtl::StringSplitter<>::Split(std::string(org_string), delimieters, des);
    str_vec_print();
    des.clear();
    MXC::StringUtl::StringSplitter<>::Split(org_string, delimieters, des);
    str_vec_print();
    des.clear();
    return 0;
}