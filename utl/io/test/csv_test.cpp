//
// Created by Mux on 2021/10/25.
//
#include "../csv.hpp"

using namespace MXC;using namespace std;;

int main() {
    IO::CSVReader reader("./csv_tester.csv");
    cout << reader;
    try {
        std::vector<gl_str> col;
        reader.get_raw_by_first_col("Linky", col);
        for (gl_str &s: col) {
            cout << s << ", ";
        }
        col.clear();
        reader.get_col_by_title("Name", col);
        for (gl_str &s: col) {
            cout << s << ", ";
        }
    } catch (Exp::InvalidArgumentError &error) {
        cerr << error;
    }
    IO::CSVReader reader1 = std::move(reader); // to test move
    cout << reader;
    return 0;
}
