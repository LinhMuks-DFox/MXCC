//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"

using namespace MXC; using namespace std;

int main() {
    IO::CSVReader reader(R"(G:\MXCC\utl\io\test\csv_tester.csv)");
    cout << reader.get_content({1, 3}) << endl;
    return 0;
}
