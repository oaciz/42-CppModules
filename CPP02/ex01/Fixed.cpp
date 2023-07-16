#include "Fixed.hpp"

Fixed::Fixed() : rawbits(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &other)
{
	cout << "Copy consturctor called" << endl;
	*this = other;
}

Fixed::Fixed(const int val)
{
	cout << "Int constructor called" << endl;
	rawbits = val << bits;
}

Fixed::Fixed(const float val)
{
	cout << "Float constructor called" << endl;
	rawbits = roundf(val * (1 << bits));
}

Fixed::~Fixed()
{
	cout << "Desturctor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	cout << "Copy assigment operator called" << endl;

	if(this != &other)
		rawbits = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const
{
	return rawbits;
}

void	Fixed::setRawBits(int raw)
{
	rawbits = raw;
}

float	Fixed::toFloat() const
{
	return (float)rawbits / (1 << bits);
}

int	Fixed::toInt() const
{
	return rawbits >> bits;
}

ostream &operator<<(ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}