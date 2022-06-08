#include "ScalarInt.hpp"
#include <iostream>
#include <limits>

ScalarInt::ScalarInt() {}

ScalarInt::~ScalarInt() {}

ScalarInt::ScalarInt(const ScalarInt& other)
: Scalar(other), intScalar_(other.intScalar_), isOutOfDouble_(other.isOutOfDouble_) {}

ScalarInt& ScalarInt::operator=(const ScalarInt& other)
{
	Scalar::operator=(other);
	this->intScalar_ = other.intScalar_;
	this->isOutOfDouble_ = other.isOutOfDouble_;
	return *this;
}

ScalarInt::ScalarInt(const Input& input)
: Scalar(input), intScalar_(static_cast<int>(this->getOrgValue())), isOutOfDouble_(input.isOutOfDouble())
{}

void ScalarInt::setScalar(const Input& input)
{
	Scalar::setScalar(input);
	this->intScalar_ = static_cast<int>(Scalar::getOrgValue());
	this->isOutOfDouble_ = input.isOutOfDouble();
}

void ScalarInt::prtValueInfo() const
{
	if (!this->isInf_ && (this->isOutOfDouble_ || this->getOrgValue() > INT32_MAX || this->getOrgValue() < INT32_MIN))
	{
		std::cout << "\e[33m" << "int: Overflow or Underflow occur!" << "\e[0m" << std::endl;
	}
	else if (this->isInf_ || this->isNan_)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << this->intScalar_ << std::endl;
	}
}

