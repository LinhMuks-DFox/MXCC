set(CMAKE_MINIMUM_REQUIRED_VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
project(CSVTester)
add_executable(csv_tester csv_test.cpp)