#include "ScalarDouble.hpp"
#include <iostream>
#include <limits>

ScalarDouble::ScalarDouble() {}

ScalarDouble::~ScalarDouble() {}

ScalarDouble::ScalarDouble(const ScalarDouble& other)
: Scalar(other), doubleScalar_(other.doubleScalar_) {}

ScalarDouble& ScalarDouble::operator=(const ScalarDouble& other)
{
	Scalar::operator=(other);
	this->doubleScalar_ = other.doubleScalar_;
	return *this;
}

ScalarDouble::ScalarDouble(Input& input)
{
	Scalar::setScalar(input);
	// 🌟
	this->doubleScalar_ = this->getOrgValue();
}

void ScalarDouble::prtValueInfo() const
{
	std::string tempStr("double: ");

	if (this->isInf_)
	{
		if (this->doubleScalar_ < 0)
		{
			tempStr.append("-inf");
		}
		else if (this->doubleScalar_ > 0)
		{
			tempStr.append("inf");
		}
	}
	else if (this->isNan_)
	{
		tempStr.append("nan");
	}
	else if	(this->getOrgValue() > std::numeric_limits<double>::max() ||
				this->getOrgValue() < std::numeric_limits<double>::min())
	{
		tempStr.append("Non displayable");
	}
	else
	{
		tempStr += std::to_string(this->doubleScalar_);
	}
	std::cout << tempStr << std::endl;
}

