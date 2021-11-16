//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"

using namespace MXC; using namespace std;

int main() {
    IO::Logger logger(R"(G:\MXCC\utl\io\test\logger_test.log)");
    logger.set_format("%t| time:<%Y-%M-%D>, [%H:%m:%s]:\n\t%c");
    logger.info_console("Program start");
    logger.error_console("Program crashed, an invalid argument was passed");
    logger.error("Program crashed, an invalid argument was passed");
    return 0;
}
