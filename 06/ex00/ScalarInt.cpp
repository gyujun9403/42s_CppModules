#include "ScalarInt.hpp"
#include <iostream>
#include <limits>

ScalarInt::ScalarInt() {}

ScalarInt::~ScalarInt() {}

ScalarInt::ScalarInt(const ScalarInt& other)
: Scalar(other), intScalar_(other.intScalar_) {}

ScalarInt& ScalarInt::operator=(const ScalarInt& other)
{
	Scalar::operator=(other);
	this->intScalar_ = other.intScalar_;
	return *this;
}

ScalarInt::ScalarInt(Input& input)
{
	Scalar::setScalar(input);
	// 🌟
	this->intScalar_ = static_cast<int>(this->getOrgValue());
}

void ScalarInt::prtValueInfo() const
{
	std::string tempStr("int: ");

	if (this->isInf_ || this->isNan_ ||
		this->getOrgValue() > INT32_MAX || this->getOrgValue() < INT32_MIN)
	{
		tempStr.append("Non displayable");
	}
	else
	{
		tempStr += "'";
		tempStr += this->intScalar_;
		tempStr += "'";
	}
	std::cout << tempStr << std::endl;
}

