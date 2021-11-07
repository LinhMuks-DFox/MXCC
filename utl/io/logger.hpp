//
// Created by Mux on 2021/11/6.
//

#ifndef MXC_LOGGER_HPP
#define MXC_LOGGER_HPP

#include "../_object.hpp"
#include "../_builtin_exception.hpp"

namespace MXC::IO {
    class Logger : public object {
    public:
        enum LogType {
            Error, Info, Debug, Warn
        };
    private:
        gl_str _fmt = "[%t]time:<%Y-%M-%D %H:%m:%s>,content:%c ";//[Debug]2021-11-6<23:13:56>: this is a debug msg;
        gl_str _path;
        std::ofstream *_log_f = nullptr;
    private:
        void _finalize_file_handle() {
            _log_f->close();
            delete _log_f;
            _log_f = nullptr;
        }

        void _release_handle() { _log_f = nullptr; }

        void _flush_log_file() const { _log_f->flush(); }

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


        [[nodiscard]] gl_str _build_content(LogType type, const gl_str &content) const {
            std::time_t t = std::time(nullptr);   // get time now
            std::tm *now = std::localtime(&t);
            std::stringstream s_res;
            std::stringstream s_fmt(_fmt);
            while (s_fmt.good()) {
                char c = (char) s_fmt.get();
                if (c == EOF) break;
                if (c == '%') {
                    s_res << [&s_fmt, &now, &type, &content]() -> gl_str {
                        switch (s_fmt.peek()) {
                            case 't':
                                return [&type]() {
                                    switch (type) {
                                        case LogType::Error:
                                            return "FATAL";
                                        case Info:
                                            return "INFO";
                                        case Debug:
                                            return "DEBUG";
                                        case Warn:
                                            return "WARN";
                                        default:
                                            return "LOGGER-UNKNOWN-LOG-TYPE";
                                    }
                                }();
                            case 'Y':
                                return std::to_string(now->tm_year + 1900);
                            case 'M':
                                return std::to_string(now->tm_mon + 1);
                            case 'D':
                                return std::to_string(now->tm_mday);
                            case 'H':
                                return std::to_string(now->tm_hour);
                            case 'm':
                                return std::to_string(now->tm_min);
                            case 's':
                                return std::to_string(now->tm_sec);
                            case 'c':
                                return content;
                            case '%':
                                return "%";
                            default:
                                return "Unknown Log Format.";
                        }
                    }();
                    s_fmt.ignore(); // to skip the fmt char.
                    continue;
                }
                s_res << c;
            }
            if (_fmt.back() != '\n')
                s_res << "\n";
            return s_res.str();
        }

    public:
        void error(const gl_str &msg) const noexcept { *_log_f << _build_content(LogType::Error, msg); }

        template<class Exp=Exp::LoggerError>
        void log_and_raise_error(const gl_str &msg) const {
            error(msg);
            _flush_log_file();
            throw Exp(msg);
        }

        void info(const gl_str &msg) const noexcept { *_log_f << _build_content(LogType::Info, msg); }

        void warn(const gl_str &msg) const noexcept { *_log_f << _build_content(LogType::Warn, msg); }

        void debug(const gl_str &msg) const noexcept { *_log_f << _build_content(LogType::Debug, msg); }

    public:

        void error_console(const gl_str &msg) const noexcept {
            fprintf(stderr, "%s", _build_content(LogType::Error, msg).c_str());
            fflush(stderr);
        }

        void info_console(const gl_str &msg) const noexcept {
            fprintf(stdout, "%s", _build_content(LogType::Info, msg).c_str());
            fflush(stdout);
        }

        void warn_console(const gl_str &msg) const noexcept {
            fprintf(stdout, "%s", _build_content(LogType::Warn, msg).c_str());
            fflush(stdout);
        }

        void debug_console(const gl_str &msg) const noexcept {
            fprintf(stdout, "%s", _build_content(LogType::Debug, msg).c_str());
            fflush(stdout);
        }

    public:

        void log_to_std_ostream(std::ostream &ost, const gl_str &content, LogType type) const {
            ost << _build_content(type, content);
        }
    };

}
#endif //MXC_LOGGER_HPP
