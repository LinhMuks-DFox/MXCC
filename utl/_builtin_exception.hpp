#ifndef MXC__BUILTIN_EXCEPTION_HPP
#define MXC__BUILTIN_EXCEPTION_HPP

#include "_object.hpp"

namespace MXC {
    class BaseException : public object, public std::runtime_error {
    protected:
        gl_str _msg;
    public:
        explicit BaseException(const char *const msg) :
            _msg(msg), std::runtime_error(msg), object("MXC::BaseException", 1) {}

        explicit BaseException(const gl_str &msg) :
            _msg(msg), std::runtime_error(msg), object("MXC::BaseException", 1) {}

        BaseException(const BaseException &exp) = delete;

        friend inline const std::ostream &operator<<(const std::ostream &os, const BaseException &exp) const {
            os << exp.to_string();
            return os;
        }

        virtual gl_str what() {
            return _msg;
        }

        [[nodiscard]] gl_str to_string() const override {
            return this->my_type.type_name + ": " + this->_msg;
        }
    };
}
#endif //MXC__BUILTIN_EXCEPTION_HPP
