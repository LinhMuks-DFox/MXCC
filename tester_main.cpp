//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"

using namespace MXC; using namespace std;
int main() {
    gl_str text = "Huffman coding is a data compression algorithm.";
    auto ss = stringstream(text); std::unordered_map<char, uint64> fre;
    Coding::HuffmanTree::word_frequency_stat(ss, fre);
    auto* tree = new Coding::HuffmanTree();
    tree->build_me(fre);
    cout << tree->decode(tree->encode(text)) << endl;
    cout << tree->encode('.');
    delete tree;
    return 0;
}
