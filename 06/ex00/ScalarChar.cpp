#include "ScalarChar.hpp"
#include <iostream>
#include <climits>

ScalarChar::ScalarChar() {}

ScalarChar::~ScalarChar() {}

ScalarChar::ScalarChar(const ScalarChar& other)
: Scalar(other), charValue_(other.charValue_) {}

ScalarChar& ScalarChar::operator=(const ScalarChar& other)
{
	// 🌟 call parent's assignment operator
	Scalar::operator=(other);
	this->charValue_ = other.charValue_;
	return *this;
}

ScalarChar::ScalarChar(const Input& input) throw(std::exception)
: Scalar(input), charValue_(static_cast<char>(Scalar::getOrgValue())) {}

bool ScalarChar::setValue(const Input& input)
{
	Scalar::setScalar(input);
	this->charValue_ = static_cast<char>(Scalar::getOrgValue());
}

// @overriding
void ScalarChar::prtValueInfo() const
{
	std::string tempStr("char: ");

	// http://www.cplusplus.com/forum/general/128714/
	if (this->isInf_ || this->isNan_ || 
		this->getOrgValue() > CHAR_MAX || this->getOrgValue() < 0 ||
		!std::isprint(this->charValue_))
		tempStr.append("Non displayable");
	else
	{
		tempStr += "'";
		tempStr += this->charValue_;
		tempStr += "'";
	}
	std::cout << tempStr << std::endl;
}
