//
// Created by Mux on 2021/10/25.
//
#include "../csv.hpp"

using namespace MXC;using namespace std;;

int main() {
    IO::CSVReader reader("./csv_tester.csv");
    cout << reader;
    IO::CSVReader reader1 = std::move(reader);
    cout << reader;
    return 0;
}
