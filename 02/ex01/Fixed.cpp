#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixPointValue_ = 0;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixPointValue_ = other.fixPointValue_;
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int data)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixPointValue_ = data << this->fractionalBits_;
}

Fixed::Fixed(const float data)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixPointValue_
		= static_cast<int>(roundf(data * (1 << this->fractionalBits_)));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixPointValue_;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixPointValue_ = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixPointValue_) / (1 << this->fractionalBits_);
}
int Fixed::toInt(void) const
{
	return static_cast<int>(this->toFloat());
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}