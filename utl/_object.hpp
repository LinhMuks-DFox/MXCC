#ifndef MXC__OBJECT_HPP
#define MXC__OBJECT_HPP

#if __cplusplus <= 202003L

#import "_config.hpp"

#else
#include <_config.hpp>
#endif
namespace MXC {
    struct Type {
        gl_str type_name;
        uint32 generation;
    }; // for RTTI
    class object {
        Type my_type {"objcet", 0};

        [[nodiscard]] virtual gl_str to_string() const {
            return my_type.type_name;
        }

        friend std::ostream& operator<<(std::ostream& os, const MXC::object& obj) {
            os << obj.to_string();
            return os;
        }
    };
}

#endif //MXC__OBJECT_HPP
