#include "ScalarChar.hpp"
#include <iostream>
#include <climits>

ScalarChar::ScalarChar()
{
	this->input_ = NULL;
}

ScalarChar::~ScalarChar(){ ;}

ScalarChar::ScalarChar(const ScalarChar& other)
{
	this->input_ = other.input_;
	this->scalar_ = other.scalar_;
}

ScalarChar& ScalarChar::operator=(const ScalarChar& other)
{
	this->input_ = other.input_;
	this->scalar_ = other.scalar_;
	return *this;
}

ScalarChar::ScalarChar(Input& input) throw(InvalidInputException)
{
	double tempValue;

	if (input.isComiled() == false)
		throw(InvalidInputException("ScalarChar::ScalarChar(Input& input)"));
	tempValue = input.getValue();
	if (tempValue < CHAR_MIN || tempValue > CHAR_MAX)
		throw(InvalidInputException("ScalarChar::ScalarChar(Input& input)"));
	this->input_ = &input;
	// 
	this->scalar_ = static_cast<char>(tempValue);
}

// @overriding
void ScalarChar::prtValueInfo() const
{
	std::string tempStr("char: ");

	if (this->input_->isInf() || this->input_->isNan())
		tempStr.append("Non displayable");
	// http://www.cplusplus.com/forum/general/128714/
	else if(!std::isprint(this->scalar_))
		tempStr.append("Non displayable");
	else if(this->scalar_ < 0)
		tempStr.append("Non displayable");
	else
	{
		tempStr += "'";
		tempStr += this->scalar_;
		tempStr += "'";
	}
	std::cout << tempStr << std::endl;
}
