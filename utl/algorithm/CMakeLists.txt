add_library(MXC_algorithm SHARED
        _sorter_base.hpp
        Sorter.hpp)
target_include_directories(
        MXC_algorithm PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" }
)