cmake_minimum_required(VERSION 3.15)
project(MXC_compile_tester)
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(utl)
add_executable(test tester_main.cpp)
target_link_libraries(test MXC)


if (MSVC)
    target_compile_options(MXC PUBLIC "/Zc:__cplusplus")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /Zc:__cplusplus")
    target_compile_options(MXC PRIVATE /W4 /WX)
else ()
    target_compile_options(MXC PRIVATE -Wall
            #-Wextra -Wpedantic -Werror
            )
endif ()

if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.12.25835)
    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
endif ()