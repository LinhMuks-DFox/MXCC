
add_library( MXC_basics STATIC
        _builtin_exception.hpp
        _config.hpp
        _object.hpp
)

target_include_directories(MXC_basics PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
add_subdirectory (
        algorithm
        coding
        container
        io
        math
        String
)
