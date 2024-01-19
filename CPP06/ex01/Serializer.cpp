#include "Serializer.hpp"

uintptr_t Serializer::serialize(const Data* ptr) {
    return reinterpret_cast<uintptr_t>(const_cast<Data*>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
