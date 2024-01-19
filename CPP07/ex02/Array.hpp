#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
private:
    T* elements; // Dinamik dizi
    unsigned int size_;

public:
    // Default constructor
    Array() : elements(nullptr), size_(0) {}

    // Constructor with size
    Array(unsigned int n) : elements(new T[n]), size_(n) {}

    // Copy constructor
    Array(const Array& other) : elements(nullptr), size_(0) {
        *this = other; // Use the assignment operator
    }

    // Destructor
    ~Array() {
        std::cout << "Deffault Destructor called" << std::endl;
        delete[] elements;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;

            size_ = other.size_;
            elements = new T[size_];

            for (unsigned int i = 0; i < size_; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(size_)) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }
    unsigned int Getsize() const {
        return size_;
    }
};

#endif
