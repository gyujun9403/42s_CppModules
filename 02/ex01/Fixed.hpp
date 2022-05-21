#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixPointValue_;
	const static int fractionalBits_ = 8;
public: 
	// ********[canonical class form]********
	Fixed();								// default constructor
	~Fixed();								// destructor
	Fixed(const Fixed& other);				// copy constructor
	Fixed& operator=(const Fixed& other);	// (copy) assignment operator
	// **************************************

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	Fixed(const int data);
	Fixed(const float data);
	float toFloat( void ) const;
	int toInt( void ) const;

	// ⬇️ this op overriding fixA << fixB. That equals fixA.opeartor<<(fixB). not std::cout << fixB.
	//std::ostream& operator<<(const Fixed& fixed);
	// ⬇️ [❌error] too many parameters for this operator functionC/C++(344)
	//std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

// 🌟Stream extraction and insertion op should be overrided at out side of class.
// Below define std::cout << fixA, that equals operator<<(std::cout, fixA).
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif