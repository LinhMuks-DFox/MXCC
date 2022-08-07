//
// Created by Mux on 2022/06/13.
//

#ifndef MXC_STRING_UTL_HPP
#define MXC_STRING_UTL_HPP

#include "../_object.hpp"

namespace MXC::StringUtl {

    template<class StringContainer = std::vector<gl_str>>
    class [[deprecated("Use Split function in String::Utl")]] StringSplitter
        : public object{
            public: StringSplitter():
                    object("MXC::StringUtl::StringSplitter", 1){}

            public: static void inline Split(
                    const char *const cstyle_str, const gl_str &delimiters,
                    StringContainer &des){char * p = (char *) cstyle_str;
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
}// namespace MXC::StringUtl

static void inline Split(const gl_str &str, const gl_str &delimiters,
                         StringContainer &des) {
    gl_str buffer;
    for (const auto ch : str) {
        if (delimiters.find(ch) != gl_str::npos) {
            des.push_back(buffer);
            buffer.clear();
        } else
            buffer += ch;
    }
}

static void inline Split(const char *const cstyle_str,
                         const char *const delimiters, StringContainer &des,
                         size_t exit_length = 0) {
    gl_str buffer;
    char *p = (char *) cstyle_str;
    bool size_check = exit_length != 0;
    size_t cur_p = 0;
    auto is_delimiter = [&delimiters](char c) -> bool {
        char *p = (char *) delimiters;
        for (; *p; ++p) {
            if (*p == c) return true;
        }
        return false;
    };
    for (; *p; ++p, ++cur_p) {
        if (size_check && cur_p == exit_length) { break; }
        if (is_delimiter(*p)) {
            des.push_back(buffer);
            buffer.clear();
        } else
            buffer += *p;
    }
}
}
;

template<class StringContainer = std::vector<gl_str>>
static void inline Split(const gl_str &str, const gl_str &delimiters,
                         StringContainer &des) {
    gl_str buffer;
    for (const auto ch : str) {
        if (delimiters.find(ch) != gl_str::npos) {
            if (!buffer.empty()) des.push_back(buffer);
            buffer.clear();
        } else
            buffer += ch;
    }
}

template<class StringContainer = std::vector<gl_str>>
static void inline Split(const char *const cstyle_str,
                         const char *const delimiters, StringContainer &des,
                         size_t exit_length = 0) {
    gl_str buffer;
    bool size_check = exit_length != 0;
    size_t cur_p = 0;
    std::unordered_set<char> delimiters_set;
    for (auto *p = const_cast<char *>(delimiters); *p; ++p) {
        delimiters_set.insert(*p);
    }
    auto is_delimiter = [&delimiters_set](char c) -> bool {
        return delimiters_set.find(c) != std::end(delimiters_set);
    };
    for (char *p = const_cast<char *>(cstyle_str); *p; ++p, ++cur_p) {
        if (size_check && cur_p == exit_length) { break; }
        if (is_delimiter(*p)) {
            if (!buffer.empty()) des.push_back(buffer);
            buffer.clear();
        } else
            buffer += *p;
    }
}

template<class IterableStringContainer = std::vector<gl_str>>
static gl_str inline Join(const char *const str,
                          IterableStringContainer &container) {}
}
#endif//MXC_STRING_UTL_HPP
