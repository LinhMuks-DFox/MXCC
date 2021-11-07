#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream s_res;
    std::stringstream s_fmt("[%Y]%Y-%M-%D<%H:%m:%s>:%c");
    while (s_fmt.good() && s) {
        char c = (char) s_fmt.get();
        if (c == EOF) break;
        if (c == '%') {
            switch (s_fmt.peek()) {
                case 't':
                    s_res << "Type";
                    break;
                case 'Y':
                    s_res << "Year";
                    break;
                case 'M':
                    s_res << "Month";
                    break;
                case 'D':
                    s_res << "Day";
                    break;
                case 'H':
                    s_res << "Hour";
                    break;
                case 'm':
                    s_res << "min";
                    break;
                case 's':
                    s_res << "sec";
                    break;
                case 'c':
                    s_res << "content";
                    break;
            }
            s_fmt.get();
            continue;
        }
        s_res << c;
    }
    std::cout << s_res.str();
    return 0;
}
