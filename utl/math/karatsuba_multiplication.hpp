//
// Created by Mux on 2021/12/11.
//

#ifndef MXC_KARATSUBA_MULTIPLICATION_HPP
#define MXC_KARATSUBA_MULTIPLICATION_HPP

#include "_math_config.h"

namespace MXC::Math {
    // Unimplemented
    class [[deprecated ("Unimplemented yet.")]] KaratsubaArray : object {
    private:
        std::vector<uint64> _integer_part;
        PNSign _sign = Zero;

    public:
        KaratsubaArray() {
            _integer_part.push_back(0);
        }

        explicit KaratsubaArray(const gl_str &str) {
            for (auto ch: str) {
                _integer_part.push_back(char_int_to_int(ch));
            }
        }

    public:
        [[nodiscard]] uint64 at(size_t i) const {
            if (i > _integer_part.size())
                throw Exp::IndexError("Index i is out of range. range: 0~" + std::to_string(i) + ", but:" + std::to_string(i));
            return _integer_part[i];
        }

        uint64 size() const {
            return _integer_part.size();
        }
    };
}
#endif //MXC_KARATSUBA_MULTIPLICATION_HPP
