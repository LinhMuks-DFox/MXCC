#ifndef MXC_HASHMAP_HPP
#define MXC_HASHMAP_HPP

#include "../_config.hpp"
#include "../_object.hpp"

namespace MXC::Container {
    template<class T, class HashCode = size_t>
    concept GetHashable = requires(const T &obj) {
                              {
                                  obj.get_hash()
                                  } -> std::convertible_to<HashCode>;
                          };


}
#endif//MXC_HASHMAP_HPP
