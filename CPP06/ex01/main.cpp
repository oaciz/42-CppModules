#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data orijinalData;
    orijinalData = Data(42);

    uintptr_t serializedPtr = Serializer::serialize(&orijinalData);
    std::cout << "Serialization Value: " << serializedPtr << std::endl;

    Data* deserializeData = Serializer::deserialize(serializedPtr);

    if (deserializeData->getValue() == orijinalData.getValue()) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Original Data Value: " << orijinalData.getValue() << std::endl;
    } else {
        std::cerr << "Serialization and deserialization unsuccessful!" << std::endl;
    }

    return 0;
}
