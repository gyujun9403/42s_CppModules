#include "Fixed.hpp"

int Fixed::fractionalBits_ = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixPointValue_ = 0;
}

// const도 인자로 전달될수 있게 하기 위해 const를 쓴다.
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignation operator called" << std::endl;
	this->fixPointValue_ = other.fixPointValue_;
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	// Fixed::operator= called
	*this = other;
	//this->fixPointValue_ = other.fixPointValue_;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixPointValue_;
}

void Fixed::setRawBit(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixPointValue_ = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}