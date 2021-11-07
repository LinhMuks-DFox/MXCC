//
// Created by Mux on 2021/10/25.
//
#include "utl/MXC.hpp"

using namespace MXC; using namespace std;

int main() {
    IO::Logger logger(R"(G:\MXCC\utl\io\test\logger_test.log)");
    logger.error("An error occurred, program crashed down.");
    logger.warn("An illegitimate parameter is forced to be passed in.");
    return 0;
}
