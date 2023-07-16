#include "Fixed.hpp"

Fixed::Fixed() : rawbits(0) {}

Fixed::Fixed(const int val) : rawbits(val << bits) {}

Fixed::Fixed(const float val) : rawbits(roundf(val * (1 << bits))) {}

Fixed::Fixed(const Fixed &other) : rawbits(other.rawbits) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    rawbits = other.getRawBits();
    return *this;
}

int Fixed::toInt() const
{
    return rawbits >> bits;
}

float Fixed::toFloat() const
{
    return (float)rawbits / (1 << bits);
}

int Fixed::getRawBits(void) const
{
    return rawbits;
}

void Fixed::setRawBits(int const raw)
{
    rawbits = raw;
}

bool Fixed::operator>(const Fixed &other) const
{
    return (rawbits > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (rawbits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (rawbits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (rawbits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (rawbits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (rawbits != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(rawbits + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(rawbits - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((rawbits * other.getRawBits()) >> bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((rawbits << bits) / other.getRawBits());
    return result;
}

Fixed &Fixed::operator++()
{
    rawbits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed &Fixed::operator--()
{
    rawbits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    operator--();
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

ostream &operator<<(ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}