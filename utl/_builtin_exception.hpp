#ifndef MXC__BUILTIN_EXCEPTION_HPP
#define MXC__BUILTIN_EXCEPTION_HPP

#include <utility>

#include "_object.hpp"

namespace MXC::Exp {
    class [[nodiscard]] BaseException : public object,
                                        public std::runtime_error {
    protected:
        gl_str _msg;

    protected:
        BaseException(gl_str msg, const gl_str &type, uint32 generation)
            : object(type, generation),
              _msg(std::move(msg)), std::runtime_error(msg) {}

    public:
        explicit BaseException(const char *const msg)
            : _msg(msg), std::runtime_error(msg),
              object("MXC::Exp::BaseException", 1) {}

        explicit BaseException(const gl_str &msg)
            : _msg(msg), std::runtime_error(msg),
              object("MXC::Exp::BaseException", 1) {}

        BaseException(const BaseException &exp) = delete;

        virtual const char *what() { return _msg.c_str(); }

        [[nodiscard]] gl_str to_str() const noexcept override {
            return this->my_type.type_name + ": " + this->_msg;
        }
    };

    class InvalidOperation : public BaseException {
    public:
        explicit InvalidOperation(const char *const msg)
            : BaseException(msg, "MXC::Exp::InvalidOperation", 2) {}

        explicit InvalidOperation(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::InvalidOperation", 2) {}
    };

    class InvalidArgumentError : public BaseException {
    public:
        explicit InvalidArgumentError(const char *const msg)
            : BaseException(msg, "MXC::Exp::InvalidArgumentError", 2) {}

        explicit InvalidArgumentError(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::InvalidArgumentError", 2) {}
    };

    class IOError : public BaseException {
    public:
        explicit IOError(const char *const msg)
            : BaseException(msg, "MXC::Exp::IOError", 2) {}

        explicit IOError(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::IOError", 2) {}
    };

    class UnImplementedError : public BaseException {
    public:
        explicit UnImplementedError(const char *const msg)
            : BaseException(msg, "MXC::Exp::UnImplementedError", 2) {}

        explicit UnImplementedError(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::UnImplementedError", 2) {}
    };

    class LoggerError : public BaseException {
    public:
        explicit LoggerError(const char *const msg)
            : BaseException(msg, "MXC::Exp::LoggerError", 2) {}

        explicit LoggerError(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::LoggerError", 2) {}
    };

    class EncodeError : public BaseException {
    public:
        explicit EncodeError(const char *const msg)
            : BaseException(msg, "MXC::Exp::EncodeError", 2) {}

        explicit EncodeError(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::EncodeError", 2) {}
    };

    class IndexError : public BaseException {
    public:
        explicit IndexError(const char *const msg)
            : BaseException(msg, "MXC::Exp::IndexError", 2) {}

        explicit IndexError(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::IndexError", 2) {}
    };

    class BadConvert : public BaseException {
    public:
        explicit BadConvert(const char *const msg)
            : BaseException(msg, "MXC::Exp::BadConvert", 2) {}

        explicit BadConvert(const gl_str &msg)
            : BaseException(msg, "MXC::Exp::BadConvert", 2) {}
    };
}// namespace MXC::Exp
#endif//MXC__BUILTIN_EXCEPTION_HPP
