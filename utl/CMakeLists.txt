project(MXC)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
add_library(MXC SHARED
        _object.hpp
        _config.hpp
        _builtin_exception.hpp
        algorithm/_sorter_base.hpp
        algorithm/Sorter.hpp

        coding/huffman.hpp

        container/HashMap.hpp
        container/IList.hpp
        container/JumpList.hpp
        container/LinkedList.hpp
        container/OrderedVector.hpp
        container/Vector.hpp

        io/csv.hpp
        io/logger.hpp

        math/_math_config.h
        math/karatsuba_multiplication.hpp
        math/math.hpp
        math/statistics.hpp

        String/StringUtl.hpp
        String/String.hpp
)
target_include_directories(MXC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(MXC PROPERTIES LINKER_LANGUAGE CXX)

