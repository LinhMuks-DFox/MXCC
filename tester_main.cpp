//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"

using namespace MXC;using namespace std;;

int main() {
    IO::CSVReader reader(R"(G:\MXCC\utl\io\test\csv_tester.csv)");
    // cout << reader;
    std::vector<gl_str> col;
    reader.get_raw_by_first_col("Linky", col);
    for (gl_str &s: col) {
        cout << s << ", ";
    }
    return 0;
}
