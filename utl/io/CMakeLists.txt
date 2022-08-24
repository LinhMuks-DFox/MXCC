add_library(MXC_io SHARED csv.hpp logger.hpp)
target_include_directories(MXC_io SHARED "${CMAKE_CURRENT_SOURCE_DIR}")