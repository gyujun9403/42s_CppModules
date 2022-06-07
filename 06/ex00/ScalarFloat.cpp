#include "ScalarFloat.hpp"
#include <iostream>
#include <limits>

ScalarFloat::ScalarFloat() {}

ScalarFloat::~ScalarFloat() {}

ScalarFloat::ScalarFloat(const ScalarFloat& other)
		: Scalar(other), floatScalar_(other.floatScalar_) {}

ScalarFloat& ScalarFloat::operator=(const ScalarFloat& other)
{
	Scalar::operator=(other);
	this->floatScalar_ = other.floatScalar_;
	return *this;
}

ScalarFloat::ScalarFloat(Input& input)
{
	Scalar::setScalar(input);
	// 🌟
	this->floatScalar_ = this->getOrgValue();
}

void ScalarFloat::prtValueInfo() const
{
	std::string tempStr("double: ");

	if (this->isInf_)
	{
		if (this->floatScalar_ < 0)
		{
			tempStr.append("-inff");
		}
		else if (this->floatScalar_ > 0)
		{
			tempStr.append("inff");
		}
	}
	else if (this->isNan_)
	{
		tempStr.append("nan");
	}
	else if	(this->getOrgValue() > std::numeric_limits<float>::max() ||
				this->getOrgValue() < std::numeric_limits<float>::min())
	{
		tempStr.append("Non displayable");
	}
	else
	{
		//TODO: 소수점 1자리로 변경
		tempStr += std::to_string(this->floatScalar_).append("f");
	}
	std::cout << tempStr << std::endl;
}