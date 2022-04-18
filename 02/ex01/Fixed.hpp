#pragma once

#include <iostream>

class Fixed
{
private:
	int fixPointValue_;
	static int fractionalBits_;
public: 
	// ********[canonical class form]********
	Fixed();								// default constructor
	~Fixed();								// distructor
	Fixed(const Fixed& other);				// copy constructor
	Fixed& operator=(const Fixed& other);	// (copy) assignment operator
	// **************************************

	int getRawBits(void) const;
	void setRawBit(int const raw);
	
	Fixed(const int data);
	Fixed(const float data);
	float toFloat( void ) const;
	int toInt( void ) const;
	//std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);