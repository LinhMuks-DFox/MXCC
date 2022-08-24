
add_library(
        MXC_math SHARED
        karatsuba_multiplication.hpp
        math.hpp
        statistics.hpp
)
target_include_directories(
        MXC_math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)