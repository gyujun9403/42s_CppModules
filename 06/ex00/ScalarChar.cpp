#include "ScalarChar.hpp"
#include <iostream>
#include <limits>

ScalarChar::ScalarChar() {}

ScalarChar::~ScalarChar() {}

ScalarChar::ScalarChar(const ScalarChar& other)
: Scalar(other), charScalar_(other.charScalar_), isOutOfDouble_(other.isOutOfDouble_) {}

ScalarChar& ScalarChar::operator=(const ScalarChar& other)
{
	// 🌟 call parent's assignment operator
	Scalar::operator=(other);
	this->charScalar_ = other.charScalar_;
	this->isOutOfDouble_ = other.isOutOfDouble_;
	return *this;
}

ScalarChar::ScalarChar(const Input& input)
: Scalar(input), charScalar_(static_cast<char>(Scalar::getOrgValue())), isOutOfDouble_(input.isOutOfDouble()) {}

void ScalarChar::setScalar(const Input& input)
{
	Scalar::setScalar(input);
	this->charScalar_ = static_cast<char>(Scalar::getOrgValue());
	this->isOutOfDouble_ = input.isOutOfDouble();
}

// @overriding
void ScalarChar::prtValueInfo() const
{
	if (!this->isInf_ && (this->isOutOfDouble_ || this->getOrgValue() > CHAR_MAX || this->getOrgValue() < CHAR_MIN))
	{
		std::cout << "\e[33m" << "char: Overflow or Underflow occur!" << "\e[0m" << std::endl;
	}
	else if (this->isInf_ || this->isNan_ )
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (!std::isprint(this->charScalar_) || this->getOrgValue() < 0)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" << this->charScalar_ << "'" << std::endl;
	}
}
