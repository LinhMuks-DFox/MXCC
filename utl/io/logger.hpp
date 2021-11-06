//
// Created by Mux on 2021/11/6.
//

#ifndef MXC_LOGGER_HPP
#define MXC_LOGGER_HPP

#include "../_object.hpp"
#include "../_builtin_exception.hpp"

namespace MXC::IO {
    class Logger : public object {
    private:
        enum _log_type {
            Error, Info, Debug, Warn
        };
    private:
        gl_str _fmt = "[%t]%Y-%M-%D<%H%m%s>:%c ";//[Debug]2021-11-6<23:13:56>: this is a debug msg;
        gl_str _path;
        std::ofstream *_log_f = nullptr;
    private:
        void _finalize_file_handle() {
            _log_f->close();
            delete _log_f;
            _log_f = nullptr;
        }

        void _release_handle() { _log_f = nullptr; }

    public:
        explicit Logger(const gl_str &path) noexcept: object("MXC::IO::Logger", 1) {
            this->_log_f = new std::ofstream(path, std::ios::out);
            _path = path;
        }

        explicit Logger(const gl_str &path, const gl_str &fmt) noexcept: object("MXC::IO::Logger", 1) {
            this->_log_f = new std::ofstream(path, std::ios::out);
            this->_fmt = fmt;
            _path = path;
        }

        Logger(Logger &&logger) noexcept: object("MXC::IO::Logger", 1) {
            _path = logger._path;
            _log_f = logger._log_f;
            _fmt = logger._fmt;
            logger._release_handle();
        }

        Logger &operator=(Logger &&logger) noexcept {
            if (&logger != this) {
                if (_log_f != nullptr) _finalize_file_handle();
                _path = logger._path;
                _log_f = logger._log_f;
                _fmt = logger._fmt;
                logger._release_handle();
            }
            return *this;
        }

        ~Logger() {
            _finalize_file_handle();
        }

        Logger &operator=(const Logger &) = delete;

        Logger(const Logger &) = delete;

    public:
        /*!
         * set logging format;
         * Use the % symbol to indicate the format.
         * %t:          log content type, [error, info, warn, debug]
         * %Y, %M, %D:  years, month, day
         * %H, %m, %s:  hours, minutes, seconds
         * %c:          content
         * @param fmt s
         */
        void set_format(const gl_str &fmt) noexcept { _fmt = fmt; }

    private:
        gl_str _build_content(_log_type t, const gl_str &content) {
            throw Exp::UnImplementedError("Logger._build_content() not call able, not implemented yet");
        }

    public:
        void error(const gl_str &msg) const noexcept { _log_f << _build_content(_log_type::Error, msg); }

        void info(const gl_str &msg) const noexcept { _log_f << _build_content(_log_type::Info, msg); }

        void warn(const gl_str &msg) const noexcept { _log_f << _build_content(_log_type::Warn, msg); }

        void debug(const gl_str &msg) const noexcept { _log_f << _build_content(_log_type::Debug, msg); }

    };

    Logger &&open_log() {
        throw Exp::UnImplementedError("Logger& open_log() not implemented yet.");
    }
}
#endif //MXC_LOGGER_HPP
