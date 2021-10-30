#ifndef MXCC__OBJECT_HPP
#define MXCC__OBJECT_HPP

#if __cplusplus <= 202003L

#import "_config.hpp"

#else
#include <_config.hpp>
#endif
namespace MXCC {
    struct Type {
        gl_str type_name;
        uint32 generation;
    }; // for RTTI
    class object {
        Type my_type {"objcet", 0};

        virtual gl_str to_string() {
            return my_type.type_name;
        }
    };
}

#endif //MXCC__OBJECT_HPP
