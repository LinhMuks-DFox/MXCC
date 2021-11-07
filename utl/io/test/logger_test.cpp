//
// Created by Mux on 2021/10/25.
//
#include "../logger.hpp"

using namespace MXC; using namespace std;

int main() {
    IO::Logger logger(R"(G:\MXCC\utl\io\test\logger_test.log)");
    logger.error("!!This is a error!!");
    return 0;
}
