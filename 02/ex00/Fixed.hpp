#pragma once

#include <iostream>

class Fixed
{
private:
	int fixPointValue_;	
	// ❗️const static int
	const static int fractionalBits_ = 8;

public: 
	// ********[canonical class form]********
	Fixed();								// default constructor
	~Fixed();								// destructor
	Fixed(const Fixed& other);				// copy constructor
	Fixed& operator=(const Fixed& other);	// (copy) assignment operator
	// **************************************

	int getRawBits(void) const;
	void setRawBit(int const raw);
};