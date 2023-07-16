#include "Fixed.hpp"

void Fixed::setRawBits(int rawbits)
{
	cout << "setRawBits member function called" << endl;
	this->rawbits = rawbits;
}
int Fixed::getRawBits() const
{
	cout << "getRawBits member function called" << endl;
	return rawbits;
}

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	rawbits = 0;
}

Fixed::~Fixed()
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed &t)
{
	cout << "Copy constructor called" << endl;
	*this = t;
}

Fixed& Fixed::operator=(const Fixed &fix)
{
	cout << "Copy assignment operator called" << endl;
	rawbits = fix.rawbits;
	return *this;
}
