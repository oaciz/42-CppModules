#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
private:
	int rawbits;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const Fixed &t);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	int	getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int	  toInt() const;

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	static	Fixed &min(Fixed &a, Fixed &b);
	static	const Fixed &min(const Fixed &a, const Fixed &b);

	static	Fixed &max(Fixed &a, Fixed &b);
	static const  Fixed &max(const Fixed &a, const Fixed &b);

};

ostream &operator<<(ostream &os, const Fixed &fixed);

#endif