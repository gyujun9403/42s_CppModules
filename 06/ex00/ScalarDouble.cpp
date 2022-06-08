#include "ScalarDouble.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

ScalarDouble::ScalarDouble() {}

ScalarDouble::~ScalarDouble() {}

ScalarDouble::ScalarDouble(const ScalarDouble& other)
: Scalar(other), doubleScalar_(other.doubleScalar_), isFloat_(other.isFloat_), isOutOfDouble_(other.isOutOfDouble_) {}

ScalarDouble& ScalarDouble::operator=(const ScalarDouble& other)
{
	Scalar::operator=(other);
	this->doubleScalar_ = other.doubleScalar_;
	this->isFloat_ = other.isFloat_;
	this->isOutOfDouble_ = other.isOutOfDouble_;
	return *this;
}

ScalarDouble::ScalarDouble(const Input& input)
: Scalar(input), doubleScalar_(this->getOrgValue()), isFloat_(input.isFloat()), isOutOfDouble_(input.isOutOfDouble())
{}

void ScalarDouble::setScalar(const Input& input)
{
	Scalar::setScalar(input);
	this->doubleScalar_ = this->getOrgValue();
	this->isFloat_ = input.isFloat();
	this->isOutOfDouble_ = input.isOutOfDouble();
}

void ScalarDouble::prtValueInfo() const
{
	if (!this->isInf_ && this->isOutOfDouble_)
	{
		std::cout << "\e[33m" << "double: Overflow or Underflow occur!" << "\e[0m" << std::endl;
	}
	else if (this->isInf_)
	{
		if (this->doubleScalar_ < 0)
		{
			std::cout << "double: -inf" << std::endl;
		}
		else if (this->doubleScalar_ > 0)
		{
			std::cout << "double: inf" << std::endl;
		}
	}
	else if (this->isNan_)
	{
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "double: " << this->doubleScalar_ << std::setprecision(2) << std::endl;
	}
}

