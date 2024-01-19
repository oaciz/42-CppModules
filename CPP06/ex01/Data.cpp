#include "Data.hpp"

Data::Data() : dataValue(0) {}

Data::Data(int value) : dataValue(value) {}

Data::Data(const Data& other) : dataValue(other.dataValue) {}

Data::~Data() {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        dataValue = other.dataValue;
    }
    return *this;
}

int Data::getValue() const {
    return dataValue;
}
