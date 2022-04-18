#include "Fixed.hpp"

int Fixed::fractionalBits_ = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixPointValue_ = 0;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	// 참고 : 같은 클래스끼리는 private 접근 가능
	// this->fixPointValue_ = other.fixPointValue_;
	this->fixPointValue_ = other.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	this->fixPointValue_ = other.fixPointValue_;
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