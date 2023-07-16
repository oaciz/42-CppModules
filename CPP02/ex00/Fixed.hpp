#include <iostream>
using std::cout;
using std::endl;

class Fixed
{
private:
	int rawbits;
	static const int bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed &t);
	Fixed& operator=(const Fixed &fix);
	int	getRawBits() const;
	void setRawBits(int rawbits);
};