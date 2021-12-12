//
// Created by Mux on 2021/10/25.
//
#include "../../csv.hpp"

using namespace MXC;using namespace std;

int main() {
    IO::CSVParse parse("./csv_tester.csv");
    cout << parse;
    try {
        std::vector<gl_str> col;
        parse.get_raw_by_first_col("Linky", col);
        for (gl_str &s: col) {
            cout << s << ", ";
        }
        col.clear();
        parse.get_col_by_title("Name", col);
        for (gl_str &s: col) {
            cout << s << ", ";
        }
    } catch (Exp::InvalidArgumentError &error) {
        cerr << error;
    }
    IO::CSVParse reader1 = std::move(parse); // to test move
    cout << parse;
    return 0;
}
