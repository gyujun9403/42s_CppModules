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

	// comparison operators
	bool operator==(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;

	// arithmetic operator
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;

	//Fixed operator*(Fixed& other);
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// postfix increment and decrement operator
	Fixed operator++(int);
	Fixed operator--(int);

	// prefix increment and decrement operator
	Fixed& operator++();
	Fixed& operator--();
	
	//std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
	static Fixed& min(Fixed& one, Fixed& another);
	static Fixed& max(Fixed& one, Fixed& another);
	static const Fixed& min(const Fixed& one, const Fixed& another);
	static const Fixed& max(const Fixed& one, const Fixed& another);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif