cmake_minimum_required(VERSION 3.15)
project(VectorTest)
set(CMAKE_CXX_STANDARD 17)
add_library(Vector SHARED
    ../../Vector.hpp
    tester.cpp
)

add_executable(Tester
    tester.cpp
)

target_link_libraries(Tester Vector)

