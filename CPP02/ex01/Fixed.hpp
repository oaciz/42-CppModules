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

	Fixed& operator=(const Fixed &fix);

	int	getRawBits() const;
	void setRawBits(int rawbits);

	float toFloat() const;
	int	  toInt() const;
};

ostream	&operator << (ostream &os, const Fixed &fixed);