cmake_minimum_required(VERSION 3.15)
project(MXC)

set(CMAKE_CXX_STANDARD 17)

add_library(
        MXC SHARED tester_main.cpp
        utl/MXC.hpp
        utl/_object.hpp
        utl/_config.hpp
        utl/math/math.hpp
        utl/String.hpp
        utl/math/_math_config.h
        utl/_builtin_exception.hpp
        utl/io/csv.hpp
        utl/container/LinkedList.hpp
        utl/io/logger.hpp
        utl/math/statistics.hpp

        utl/coding/huffman.hpp
)

add_executable(Tester tester_main.cpp)

target_link_libraries(Tester MXC)