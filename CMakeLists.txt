cmake_minimum_required(VERSION 3.15)
project(MXCC)

set(CMAKE_CXX_STANDARD 17)

add_library(MXCC SHARED tester_main.cpp
        utl/MXC.hpp
        utl/_object.hpp
        utl/_config.hpp
        utl/math/math.hpp
        utl/String.hpp
        utl/math/_math_config.h
        utl/_builtin_exception.hpp
        )

add_executable(Tester tester_main.cpp)

target_link_libraries(Tester MXCC)