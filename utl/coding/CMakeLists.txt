add_library(MXC_coding SHARED huffman.hpp)
target_include_directories(
        MXC_coding PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)