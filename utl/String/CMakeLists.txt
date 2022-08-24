add_library(MXC_String SHARED
        String.hpp
        StringUtl.hpp
        )

target_include_directories(
        MXC_String PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)