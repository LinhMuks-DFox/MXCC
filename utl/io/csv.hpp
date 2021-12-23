//
// Created by Mux on 2021/11/5.
//

#ifndef MXC_CSV_HPP
#define MXC_CSV_HPP

#include "../_builtin_exception.hpp"
#include "../_object.hpp"

namespace MXC::IO {
    struct csv_coordinates {
        uint64 raw, col;
    };

    class [[deprecated("Due to behaviour of std::getline() is not unique "
                       "across platforms, "
                       "the behaviour of CSVParse is also not unique and is "
                       "not cross-platform.")]] CSVParse : public object {
    private:
        gl_str _path;
        std::vector<std::vector<gl_str>> _raws{};
        uint64 _maximum_col = 0;
        csv_coordinates _iter_step{0, 0};

    private:
        void _reset_me() { _raws.clear(); }

        void parse() {
            std::ifstream _f_in(_path, std::ios::in);
            if (!_f_in.is_open())
                throw Exp::IOError("CSVParse failed to open file:" + _path);
            gl_str line;
            while (_f_in.good()) {// read file line by line
                std::vector<gl_str> cur_raw;
                std::getline(_f_in, line);
                std::stringstream ss(line);
                gl_str table;
                while (ss.good()) {// split raw by comma
                    std::getline(ss, table, ',');
                    cur_raw.push_back(table);
                }
                _maximum_col = cur_raw.size() > _maximum_col ? cur_raw.size()
                                                             : _maximum_col;
                _raws.push_back(std::move(cur_raw));
            }
            _f_in.close();
        }

    public:
        [[nodiscard]] gl_str to_str() const noexcept override {
            std::stringstream ss;
            for (const auto &raw : _raws) {
                for (const gl_str &content : raw) { ss << content << ","; }
                ss << std::endl;
            }
            return ss.str();
        }

    public:
        explicit CSVParse(const gl_str &path)
            : object("MXC::IO::CSVParse", 1) {
            _path = path;
            parse();
        }

        CSVParse &operator=(const CSVParse &) = delete;

        CSVParse(const CSVParse &) = delete;

        CSVParse(CSVParse && reader) noexcept
            : object("MXC::IO::CSVParse", 1) {
            _raws = std::move(reader._raws);
            reader._reset_me();
        }

        CSVParse &operator=(CSVParse &&reader) noexcept {
            if (&reader != this) { _raws = std::move(reader._raws); }
            // Resets the reader so that it no longer occupies resources and can validly be destroyed.
            reader._reset_me();
            return *this;
        }

        ~CSVParse() = default;

    public:
        [[nodiscard]] const std::vector<gl_str> &operator[](uint64 raw_idx)
                const {
            if (raw_idx > _raws.size())
                throw Exp::InvalidArgumentError(
                        "CSVParse.get_raw(uint64 raw_idx) failed. raw_idx is "
                        "out of range.");
            return _raws[raw_idx];
        }

        void get_col(std::vector<gl_str> & v, uint64 col_idx) const noexcept {
            if (col_idx > _maximum_col) { return; }
            for (const std::vector<gl_str> &raw : _raws) {
                if (raw.size() < col_idx) { continue; }
                v.push_back(raw.at(col_idx));
            }
        }

        void get_col_by_title(const gl_str &title, std::vector<gl_str> &v)
                const {
            get_col(v, [this, &title] {
                for (uint64 i = 0; i < this->_raws[0].size(); ++i)
                    if (_raws[0][i] == title) return i;
                throw Exp::InvalidArgumentError("Can not find title:" + title);
            }());
        }

        void get_raw_by_first_col(const gl_str &first_col,
                                  std::vector<gl_str> &v) const {
            auto i = _raws.at([this, &first_col] {
                for (uint64 i = 0; i < _raws.size(); ++i)
                    if (_raws[i][0] == first_col) return i;
                throw Exp::InvalidArgumentError("Can not find raw:" +
                                                first_col);
            }());
            std::copy(i.begin(), i.end(), std::back_inserter(v));
        }

        [[nodiscard]] uint64 raw_cnt() const noexcept { return _raws.size(); }

        [[nodiscard]] uint64 maximum_col() const noexcept {
            return _maximum_col;
        }

        [[nodiscard]] gl_str query_content(csv_coordinates c) const {
            return _raws[c.raw][c.col];
        }
    };

    class [[deprecated("Unimplemented yet.")]] CSVWriter : public object {
    private:
        std::ofstream *_f_o = nullptr;
        gl_str _path;

    private:
        void _reset_me() noexcept {
            _f_o->flush();
            _f_o = nullptr;
        }

        void _release_file_handle() noexcept {
            _f_o->close();
            delete _f_o;
            _f_o = nullptr;
        }

    public:
        explicit CSVWriter(const gl_str &path)
            : object("MXC::IO::CSVWriter", 1) {
            _f_o = new std::ofstream(path, std::ios::out);
            _path = path;
        }

        CSVWriter(CSVWriter && writer) noexcept
            : object("MXC::IO::CSVWriter", 1) {
            _f_o = writer._f_o;
            writer._reset_me();
        }

        CSVWriter &operator=(CSVWriter &&writer) noexcept {
            if (this != &writer) {
                if (_f_o != nullptr) _release_file_handle();
                _f_o = writer._f_o;
                _path = writer._path;
            }
            return *this;
        }


        ~CSVWriter() { _release_file_handle(); }

        CSVWriter(const CSVWriter &) = delete;

        CSVWriter &operator=(const CSVWriter &) = delete;
    };
}// namespace MXC::IO
#endif//MXC_CSV_HPP
