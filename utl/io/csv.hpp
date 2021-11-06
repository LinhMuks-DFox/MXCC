//
// Created by Mux on 2021/11/5.
//

#ifndef MXC_CSV_HPP
#define MXC_CSV_HPP

#include "../_object.hpp"

namespace MXC::IO {
    struct csv_coordinates {
        uint64 raw, col;
    };

    class CSVReader : public object {
    private:
        gl_str _path;
        std::vector<std::vector<gl_str>> _raws{};
        uint64 _maximum_col = 0;
        csv_coordinates _iter_step{0, 0};

    private:
        void _reset_me() {
            _raws.clear();
        }


        void parse() {
            auto *_f_in = new std::ifstream(_path, std::ios::in);
            if (!_f_in->is_open())throw Exp::IOError("CSVReader failed to open file:" + _path);
            gl_str line;
            while (_f_in->good()) { // read file line by line
                std::vector<gl_str> r;
                std::getline(*_f_in, line);
                std::stringstream ss(line);
                gl_str table;
                while (ss.good()) { // split raw by comma
                    std::getline(ss, table, ',');
                    r.push_back(table);
                }
                _raws.push_back(r);
                _maximum_col = r.size() > _maximum_col ? r.size() : _maximum_col;
            }
            _f_in->close();
            delete _f_in;
        }

    public:
        [[nodiscard]] gl_str to_string() const noexcept override {
            std::stringstream ss;
            for (const auto &raw: _raws) {
                for (const gl_str &content: raw) {
                    ss << content << ",";
                }
                ss << "\n" << std::flush;
            }
            return ss.str();
        }

    public:
        explicit CSVReader(const gl_str &path) : object("MXC::IO::CSVReader", 1) {
            _path = path;
            parse();
        }

        CSVReader &operator=(const CSVReader &) = delete;

        CSVReader(const CSVReader &) = delete;

        CSVReader(CSVReader &&reader) noexcept: object("MXC::IO::CSVReader", 1) {
            _raws = std::move(reader._raws);
            reader._reset_me();
        }

        CSVReader &operator=(CSVReader &&reader) noexcept {
            if (&reader != this) {
                _raws = std::move(reader._raws);
            }
            // Resets the reader so that it no longer occupies resources and can validly be destroyed.
            reader._reset_me();
            return *this;
        }

        ~CSVReader() = default;

    public:
        [[nodiscard]] const std::vector<gl_str> &get_raw(uint64 raw_idx) const {
            if (raw_idx > _raws.size())
                throw Exp::InvalidArgumentError("CSVReader.get_raw(uint64 raw_idx) failed. raw_idx is out of range.");
            return _raws[raw_idx];
        }

        [[nodiscard]] uint64 raw_cnt() const noexcept { return _raws.size(); }

        [[nodiscard]] uint64 maximum_col() const noexcept { return _maximum_col; }

        [[nodiscard]] gl_str get_content(csv_coordinates c) const {
            return this->get_raw(c.raw).at(c.col);
        }
    };

    class CSVWriter : public object {
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
        explicit CSVWriter(const gl_str &path) : object("MXC::IO::CSVWriter", 1) {
            _f_o = new std::ofstream(path, std::ios::out);
            _path = path;
        }

        CSVWriter(CSVWriter &&writer) noexcept: object("MXC::IO::CSVWriter", 1) {
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


        ~CSVWriter() {
            _release_file_handle();
        }

        CSVWriter(const CSVWriter &) = delete;

        CSVWriter &operator=(const CSVWriter &) = delete;
    };
}
#endif //MXC_CSV_HPP
