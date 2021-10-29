#ifndef MXCC__OBJECT_HPP
#define MXCC__OBJECT_HPP

#if __cplusplus <= 202003L

#import "_config.hpp"

#else
#include <_config.hpp>
#endif
namespace MXCC {
    struct Type {
        cv_str_t type_name;

    }; // for RTTI
    class object {
        Type my_type{};

        virtual cv_str_t to_string() {
            return my_type.type_name;
        }
    };
}

#endif //MXCC__OBJECT_HPP
