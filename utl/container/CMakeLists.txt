add_library(
        MXC_container SHARED
        HashMap.hpp
        IList.hpp
        JumpList.hpp
        LinkedList.hpp
        OrderedVector.hpp
        Vector.hpp
)

target_include_directories(MXC_container "${CMAKE_CURRENT_SOURCE_DIR}")