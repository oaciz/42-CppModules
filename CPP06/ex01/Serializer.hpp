#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include "Data.hpp"
#include <cstdint>

class Serializer {
public:
    static uintptr_t serialize(const Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
