#pragma once

#include <iostream>

class Fixed
{
private:
	int fixPointValue_;
	static int fractionalBits_;
public: 
	// default constructor
	Fixed();
	// distructor
	~Fixed();
	// copy constructor
	Fixed(const Fixed& other);
	// (copy) assignment operator
	Fixed& operator=(const Fixed& other);

	int getRawBits(void) const;
	void setRawBit(int const raw);
};