cmake_minimum_required(VERSION 3.20)
project(MXCC)

set(CMAKE_CXX_STANDARD 14)

add_library(MXCC SHARED tester_main.cpp
        utl/_object.hpp utl/_config.hpp utl/math/math.hpp utl/MXCC.hpp)

add_executable(Tester tester_main.cpp)