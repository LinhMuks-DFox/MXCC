//
// Created by Mux on 2021/11/17.
//

#ifndef MXC_HUFFMAN_HPP
#define MXC_HUFFMAN_HPP

#include "../_object.hpp"
#include "../io/logger.hpp"


namespace MXC::Coding {
    /*
     * This Huffman Tree is implemented as this form:
     *                           root
     *                        0/      \1
     *                     left        right
     *                   0/    \1    0/     \1
     *                left      right  ...
     *                ...     ...     ...     ...
     * */
    class HuffmanTree : object {
    private:
        typedef std::pair<char, int> frequency_pair; // symbol, frequency
        typedef struct _huffman_tree_node {
            _huffman_tree_node *left = nullptr, *right = nullptr;
            uint64 freq = 0;
            char symbol = '\0';

            _huffman_tree_node(char ch, uint64 fre, _huffman_tree_node *left, _huffman_tree_node *right) :
                    left(left), right(right), symbol(ch), freq(fre) {}

            _huffman_tree_node() = default;

            ~_huffman_tree_node() = default;
        } node;

        struct node_cmp {
            bool operator()(node *i, node *j) { return i->freq > j->freq; }
        };

        node *_root = nullptr;
    private:
        std::unordered_map<char, gl_str> _encode_map;
        std::unordered_map<gl_str, char> _decode_map;
    public:
        HuffmanTree() : object("MXC::Coding::HuffmanTree", 1) {}

        explicit HuffmanTree(std::istream &in) : object("MXC::Coding::HuffmanTree", 1) {
            std::unordered_map<char, uint64> f_table;
            word_frequency_stat_and_build(in, f_table);
        }

    public:
        void build_me(const std::unordered_map<char, uint64> &frequency_table) {
            std::priority_queue<node *, std::vector<node *>, node_cmp> pq;
            for (auto pair: frequency_table) {
                pq.push(new node(pair.first, pair.second, nullptr, nullptr));
            }
            while (pq.size() != 1) {
                node *left = pq.top();
                pq.pop();
                node *right = pq.top();
                pq.pop();
                uint64 sum = left->freq + right->freq;
                pq.push(new node('\0', sum, left, right));
            }
            _root = pq.top();
            _build_encode_map(_root, "");
            _build_decode_map();
            _free_tree(_root);
            _root = nullptr;
        }

        void word_frequency_stat_and_build(std::istream &in, std::unordered_map<char, uint64> &table) {
            word_frequency_stat(in, table);
            build_me(table);
        }

    private:
        void _free_tree(node *node) noexcept {
            if (node == nullptr) return;
            _free_tree(node->left);
            _free_tree(node->right);
            delete node;
        }

        void _build_encode_map(node *node, const gl_str &str) {
            if (node == nullptr) return;
            if (!node->left && !node->right) { _encode_map[node->symbol] = str; }
            _build_encode_map(node->left, str + "0");
            _build_encode_map(node->right, str + "1");
        }

        void _build_decode_map() { for (auto &[key, value]: _encode_map) _decode_map[value] = key; }

    public:
        ~HuffmanTree() { _free_tree(_root); }

        HuffmanTree(const HuffmanTree &) = delete;

        HuffmanTree &operator=(const HuffmanTree &) = delete;


        HuffmanTree &operator=(HuffmanTree &&tree) noexcept {
            if (this != &tree) {
                this->_decode_map = std::move(tree._decode_map);
                this->_encode_map = std::move(tree._encode_map);
                if (tree._root != nullptr) tree._free_tree(tree._root);
            }
            return *this;
        }

        HuffmanTree(HuffmanTree &&tree) noexcept: object("MXC::Coding::HuffmanTree", 1) {
            if (this != &tree) {
                this->_decode_map = std::move(tree._decode_map);
                this->_encode_map = std::move(tree._encode_map);
                if (tree._root != nullptr) tree._free_tree(tree._root);
            }
        }

    public:
        [[nodiscard]] gl_str to_string() const noexcept override {
            return to_json_string();
        }

    public:
        gl_str encode(char c) { return _encode_map[c]; }

        gl_str encode(const gl_str &input) {
            std::stringstream ss;
            for (char i: input) { ss << _encode_map[i]; }
            ss << std::flush;
            return ss.str();
        }

        gl_str decode(const gl_str &bytes) {
            gl_str cur;
            std::stringstream ss;
            auto contains = [this, &cur] { return this->_decode_map.find(cur) != this->_decode_map.end(); };
            for (auto c: bytes) {
                if (contains()) {
                    ss << this->_decode_map[cur];
                    cur = "";
                }
                cur += c;
            }
            if (!cur.empty()) ss << _decode_map[cur];
            return ss.str();
        }

        gl_str to_json_string() const noexcept {
            std::stringstream sb;
            sb << "{\"encode\":" << "{";
            for (auto &[key, value]: _encode_map)
                sb << "\"" << key << "\"" << ':' << "\"" << value << "\"" << "," << std::flush;
            sb << "},";
            sb << "\"decode\":" << "{";
            for (auto &[key, value]: _decode_map)
                sb << "\"" << key << "\"" << ':' << "\"" << value << "\"" << "," << std::flush;
            sb << "}}";
        }

        void dump_tree_to_json(std::ofstream &out) const {
            out << to_json_string();
        }

    public:
        static void word_frequency_stat(std::istream &in, std::unordered_map<char, uint64> &table) {
            while (in.good()) {
                char c = (char) in.get();
                if (c == EOF) break;
                table[c]++;
            }
        }
    };

}
#endif //MXC_HUFFMAN_HPP
