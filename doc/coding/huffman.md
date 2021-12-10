# `MXC::Coding::HuffmanTree`

Author: Mux

This is an implementation of Huffman coding.

This implementation solves the Huffman encoding of a string of text or a string of characters.

Generate Huffman encoding by counting the word frequency of strings or texts, and decode the table.  
$$
String/text \rightarrow HuffmanTree\rightarrow Huffman Encode/DecodeTable
$$

### Methods

#### Constructing

1. `HuffmanTree()`

    Constructs a Huffman tree object, but does not construct the Huffman tree ontology.

    To generate the Huffman encoding table, decoding table, you need to call the `build_me()` method.

2. `HuffmanTree(std::istream&)`

    Construct a Huffman encoding table from the incoming text stream, decode the table.

    No need to call the build_me method manually

3. `build_me(std::unordered_map<char, uint64> &)`

    From the given word frequency table, a Huffman tree is constructed and the tree is traversed to generate the corresponding encoding and decoding tables.

4. `word_frequency_stat_and_build(std::istream &in, std::unordered_map<char, uint64> &)`

    Parse the given input stream, add the word frequency data to the incoming frequency table object reference, then generate a Huffman tree, and analyze the Huffman tree to generate the decoding, encoding table

#### for encode/ decode

1. `gl_str encode(char ch)`

    Encodes the given character. The result of the encoding is a std::string object containing only 0 and 1. It is possible to iterate over this string and convert it to its corresponding binary form

2. `gl_str encode(const gl_str&)`

    Encodes the given string. The result of the encoding is a std::string object containing only 0 and 1. It is possible to iterate over this string and convert it to its corresponding binary form

3. `gl_str decode(const gl_str&)`

    Decodes the given bytes (std::string objects containing only 0s and 1s).

#### dump tree, save tree

1. `dump_tree_in_json_to()`
2. `to_json_string()`
3. `word_frequency_stat()`



### How to Use

```C++
#include "utl/MXC.hpp"

using namespace MXC; using namespace std;
int main() {
    gl_str text = "Huffman coding is a data compression algorithm.";
    auto ss = stringstream(text);
    auto* tree = new Coding::HuffmanTree(ss);
    cout << tree->encode(text) << endl;
    cout << tree->encode('.');
    delete tree;
    return 0;
}
```

Code above output:
```bash
100101100111101011010011101010001011111000111111000100010011101000011010101010111111010110000101011111000101111100101110
11110000110011000000110001010101101111001100111101000110001110010111110110
110110
```

