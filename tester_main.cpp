//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"

using namespace MXC; using namespace std;
int main() {
    gl_str text = "Huffman coding is a data compression algorithm.";
    auto ss = stringstream(text);
    Coding::HuffmanTree tree(ss);
    cout << tree.encode(text) << endl;
    cout << tree.encode('.');
    return 0;
}
