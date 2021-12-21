cmake_minimum_required(VERSION 3.20)
project(MXC)
set(CMAKE_CXX_STANDARD 17)

add_library( MXC SHARED tester_main.cpp
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
        utl/math/karatsuba_multiplication.hpp
)
# put this after add_library
target_compile_options(MXC PUBLIC "/Zc:__cplusplus")
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 /Zc:__cplusplus")
endif()
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_executable(CompileTester tester_main.cpp)
target_link_libraries(CompileTester MXC)