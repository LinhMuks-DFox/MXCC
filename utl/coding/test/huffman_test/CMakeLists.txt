cmake_minimum_required(VERSION 3.15)
project(CodingUtilTest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(TestHuffman
        huffman_test.cpp)