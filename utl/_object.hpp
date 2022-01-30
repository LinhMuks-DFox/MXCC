#ifndef MXC__OBJECT_HPP
#define MXC__OBJECT_HPP


#include "_config.hpp"
namespace MXC {
    struct Type {
        gl_str type_name;
        uint32 generation;

        friend bool operator==(const Type &type, const Type &self) {
            return type.type_name == self.type_name && type.generation == self.generation;
        }

        friend bool operator!=(const Type &type, const Type &self) {
            return !(type == self);
        }
    };// for RTTI
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

        object(object&& obj) noexcept {
            my_type.type_name = std::move(obj.my_type.type_name);
            my_type.generation = obj.my_type.generation;
            obj.constructed_obj = false;
            constructed_obj = true;
        }


        ~object() = default;

        object(const gl_str &my_type, uint32 generation) {
            this->my_type.type_name = my_type;
            this->my_type.generation = generation;
            this->constructed_obj = true;
        }

        [[nodiscard]] virtual gl_str to_str() const noexcept {
            return my_type.type_name;
        }

        [[nodiscard]] virtual Type get_type() const noexcept {
            return this->my_type;
        }

        [[nodiscard]] virtual MXC::hash_code get_hash() const noexcept {
            return reinterpret_cast<size_t>(this);
        }

        friend std::ostream &
        operator<<(std::ostream &os, const MXC::object &obj) noexcept {
            os << obj.to_str();
            return os;
        }
    };

    static inline gl_str to_string(const object &obj) noexcept {
        return obj.to_str();
    }

    template <typename T>
    struct is_object{
        constexpr static bool value = false;
    };

    template<>
    struct is_object<object> {
        constexpr static bool value = true;
    };
}// namespace MXC
#endif//MXC__OBJECT_HPP