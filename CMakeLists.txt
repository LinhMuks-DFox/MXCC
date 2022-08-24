cmake_minimum_required(VERSION 3.15)
project(MXC_compile_tester)
set(CMAKE_CXX_STANDARD 20)

add_library(MXC SHARED tester_main.cpp
        utl/MXC.hpp
        utl/_object.hpp
        utl/_config.hpp
        utl/math/math.hpp
        utl/String/String.hpp
        utl/math/_math_config.h
        utl/math/linear/linearspace.hpp
        utl/_builtin_exception.hpp
        utl/io/csv.hpp
        utl/container/LinkedList.hpp
        utl/io/logger.hpp
        utl/math/statistics.hpp
        utl/coding/huffman.hpp
        utl/math/karatsuba_multiplication.hpp
        utl/container/Vector.hpp
        utl/container/IList.hpp
        utl/container/OrderedVector.hpp
        utl/algorithm/Sorter.hpp
        utl/algorithm/_sorter_base.hpp
        utl/container/JumpList.hpp
        utl/String/StringUtl.hpp
        utl/container/HashMap.hpp)
# put this after add_library
if(MSVC)
    target_compile_options(MXC PUBLIC "/Zc:__cplusplus")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /Zc:__cplusplus")
endif()

if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.12.25835)
    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
endif()
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_executable(CompileTester tester_main.cpp)
target_link_libraries(CompileTester MXC)


# Set warning all
if(MSVC)
    target_compile_options(MXC PRIVATE /W4 /WX)
else()
    target_compile_options(MXC PRIVATE -Wall
            #-Wextra -Wpedantic -Werror
            )
endif()