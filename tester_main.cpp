//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"

using namespace MXC;using namespace std;;

int main() {
    IO::CSVReader reader(R"(G:\MXCC\utl\io\test\csv_tester.csv)");
    cout << reader;
    IO::CSVReader reader1 = std::move(reader);
    cout << reader;
    return 0;
}
