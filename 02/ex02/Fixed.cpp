#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->fixPointValue_ = 0;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->fixPointValue_ = other.fixPointValue_;
	return *this;
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->fixPointValue_ == other.fixPointValue_);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixPointValue_ > other.fixPointValue_);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->fixPointValue_ < other.fixPointValue_);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fixPointValue_ >= other.fixPointValue_);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fixPointValue_ <= other.fixPointValue_);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	// before
	//Fixed ret(this->toFloat() + other.toFloat()); -> It didn't take advantage of fixed-point.
	// 🌟after
	Fixed ret(this->fixPointValue_ + other.fixPointValue_);

	return ret;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	// before
	//Fixed ret(this->toFloat() - other.toFloat());
	// 🌟after
	Fixed ret(this->fixPointValue_ - other.fixPointValue_);

	return ret;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	// before
	//Fixed ret(this->toFloat() * other.toFloat());
	// 🌟after
	Fixed ret;

	ret.setRawBits(this->fixPointValue_ * other.fixPointValue_ / (1 << this->fractionalBits_));

	return ret;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	// before
	//Fixed ret(this->toFloat() / other.toFloat());
	// 🌟after
	Fixed ret(static_cast<float>(this->fixPointValue_) / other.fixPointValue_);

	return ret;
}

Fixed Fixed::operator++(int)
{
	Fixed ret;

	ret.fixPointValue_ = this->fixPointValue_;
	this->fixPointValue_ += 1;
	return ret;
}

Fixed Fixed::operator--(int)
{
	Fixed ret;

	ret.fixPointValue_ = this->fixPointValue_;
	this->fixPointValue_ -= 1;
	return ret;
}

Fixed& Fixed::operator++()
{
	this->fixPointValue_ += 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->fixPointValue_ -= 1;
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::Fixed(const int data)
{
	this->fixPointValue_ = data << this->fractionalBits_;
}

Fixed::Fixed(const float data)
{
	this->fixPointValue_ = static_cast<int>(roundf(data * (1 << this->fractionalBits_)));
}

int Fixed::getRawBits(void) const
{
	return this->fixPointValue_;
}

void Fixed::setRawBits(int const raw)
{
	this->fixPointValue_ = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixPointValue_) / (1 << this->fractionalBits_);
}

int Fixed::toInt(void) const
{
	return this->fixPointValue_ / (1 << this->fractionalBits_);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed& Fixed::min(Fixed& one, Fixed& another)
{
	if (one.fixPointValue_ > another.fixPointValue_)
		return another;
	else
		return one;
}

Fixed& Fixed::max(Fixed& one, Fixed& another)
{
	if (one.fixPointValue_ > another.fixPointValue_)
		return one;
	else
		return another;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& another)
{
	if (one.fixPointValue_ > another.fixPointValue_)
		return another;
	else
		return one;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& another)
{
	if (one.fixPointValue_ > another.fixPointValue_)
		return one;
	else
		return another;
}

Fixed::~Fixed()
{
	;
}
