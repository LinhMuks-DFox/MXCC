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
        bool constructed_obj = false;
        Type my_type{};

        explicit object(const char *const type) {
            this->my_type.type_name = type;
            this->my_type.generation = 1;
            this->constructed_obj = true;
        }

    public:

        explicit object() {
            my_type.type_name = "MXC::object";
            my_type.generation = 0;
        };


        ~object() = default;

        object(const char *const my_type, uint32 generation) {
            this->my_type.type_name = my_type;
            this->my_type.generation = generation;
            this->constructed_obj = true;
        }

        [[nodiscard]] virtual gl_str to_string() const {
            return my_type.type_name;
        }

        virtual Type get_type() {
            return this->my_type;
        }

        virtual MXC::hash_code get_hash() {
            std::hash<object *> h;
            return h(this);
        }

        friend std::ostream &operator<<(std::ostream &os, const MXC::object &obj) {
            os << obj.to_string();
            return os;
        }
    };

    template<typename Father, typename Son>
    bool is_instance(const Son &obj) {
        Father f;
        return f.get_type() == obj.get_type();
    }
    // [[maybe_unused]] static const object ROOT_OBJ("MXC::object", 0);
}

#endif //MXC__OBJECT_HPP
