//
// Created by Mux on 2021/10/25.
//
#include "../../csv.hpp"

using namespace MXC;
using namespace std;

int main() {
    IO::CSVParse parse("./csv_tester.csv");
    cout << parse;
    return 0;
}
