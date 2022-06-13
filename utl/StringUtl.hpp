//
// Created by Mux on 2022/06/13.
//

#ifndef MXC_STRING_UTL_HPP
#define MXC_STRING_UTL_HPP

#include "_object.hpp"

namespace MXC::StringUtl {

    template<class StringContainer = std::vector<gl_str>>
    class StringSplitter : public object {
    public:
        StringSplitter() : object("MXC::StringUtl::StringSplitter", 1) {}
    public:
        static void inline Split(const char *const cstyle_str, const gl_str &delimiters, StringContainer &des) {
            char *p = (char *) cstyle_str;
            gl_str buffer;
            while (*p != '\0') {
                // if current char is a delimiter
                if (delimiters.find(*p) != gl_str::npos) {
                    des.push_back(buffer);
                    buffer.clear();
                } else
                    buffer += (*p);
                ++p;
            }
        }
        static void inline Split(const gl_str &str, const gl_str &delimiters, std::vector<gl_str> &des) {
            gl_str buffer;
            for (const auto ch: str) {
                if (delimiters.find(ch) != gl_str::npos) {
                    des.push_back(buffer);
                    buffer.clear();
                } else
                    buffer += ch;
            }
        }
    };
}
#endif //MXC_STRING_UTL_HPP
