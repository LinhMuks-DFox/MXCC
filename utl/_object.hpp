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
    protected:
        Type my_type{"MXC::object", 0};

        explicit object(const char *const type) {
            this->my_type.type_name = type;
            this->my_type.generation = 1;
        }

    public:

        explicit object() = default;


        ~object() = default;

        object(const char *const my_type, uint32 generation) {
            this->my_type.type_name = my_type;
            this->my_type.generation = generation;
        }

        [[nodiscard]] virtual gl_str to_string() const {
            return my_type.type_name;
        }

        virtual Type get_type() {
            return this->my_type;
        }

        friend std::ostream &operator<<(std::ostream &os, const MXC::object &obj) {
            os << obj.to_string();
            return os;
        }
    };
    // [[maybe_unused]] static const object ROOT_OBJ("MXC::object", 0);
}

#endif //MXC__OBJECT_HPP
