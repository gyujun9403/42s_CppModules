#include "ScalarFloat.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

ScalarFloat::ScalarFloat() {}

ScalarFloat::~ScalarFloat() {}

ScalarFloat::ScalarFloat(const ScalarFloat& other)
: Scalar(other), floatScalar_(other.floatScalar_), isOutOfDouble_(other.isOutOfDouble_) {}

ScalarFloat& ScalarFloat::operator=(const ScalarFloat& other)
{
	Scalar::operator=(other);
	this->floatScalar_ = other.floatScalar_;
	this->isOutOfDouble_ = other.isOutOfDouble_;
	return *this;
}

ScalarFloat::ScalarFloat(const Input& input)
: Scalar(input), floatScalar_(this->getOrgValue()), isOutOfDouble_(input.isOutOfDouble())
{}

void ScalarFloat::setScalar(const Input& input)
{
	Scalar::setScalar(input);
	this->floatScalar_ = static_cast<float>(Scalar::getOrgValue());
	this->isOutOfDouble_ = input.isOutOfDouble();
}

void ScalarFloat::prtValueInfo() const
{
	if	(!this->isInf_ && 
			(this->isOutOfDouble_ || 
				(this->getOrgValue() > std::numeric_limits<float>::max() || (this->getOrgValue() > 0 && this->getOrgValue() < std::numeric_limits<float>::min())) ||
				(this->getOrgValue() < -std::numeric_limits<float>::max() || (this->getOrgValue() < 0 && this->getOrgValue() > -std::numeric_limits<float>::min()))
			)
		)
	{
		std::cout << "\e[33m" << "float: Overflow or Underflow occur!" << "\e[0m" << std::endl;
	}
	else if (this->isInf_)
	{
		if (this->floatScalar_ < 0)
		{
			std::cout << "float: -inff" << std::endl;
		}
		else if (this->floatScalar_ > 0)
		{
			std::cout << "float: inff" << std::endl;
		}
	}
	else if (this->isNan_)
	{
		std::cout << "float: nanf" << std::endl;
	}
	else
	{
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "float: " << this->floatScalar_ << "f" << std::endl;
	}
}