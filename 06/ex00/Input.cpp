#include "Input.hpp"
#include <iostream>
#include <cmath>

Input::Input(): isCompiled_(false) {}

Input::~Input() {}

Input::Input(const Input& other)
: isCompiled_(other.isCompiled_), inputStr_(other.inputStr_), value_(other.value_), isNan_(other.isNan_), isInf_(other.isInf_) { }

Input& Input::operator=(const Input& other)
{
	if (this == &other)
		return *this;	
	this->inputStr_ = other.inputStr_;
	this->value_ = other.value_;
	this->isNan_ = other.isNan_;
	this->isInf_ = other.isInf_;
	this->isCompiled_ = other.isCompiled_;
	return *this;
}

Input::Input(char* str) throw(InvalidInputException)
{
	char* pEnd;
	if (str == NULL || str[0] == '\0')
		throw (InvalidInputException("Input::Input(char* str)"));
	this->inputStr_ = str;
	this->value_ = std::strtod(this->inputStr_, &pEnd);
	if (!(pEnd[0] == '\0' || pEnd[0] == 'f' || std::isspace(pEnd[0])))
	 	throw (InvalidInputException("Input::compileInput()"));
	this->isNan_ = std::isnan(this->value_);
	this->isInf_ = std::isinf(this->value_);
}

bool Input::isComiled()
{
	return this->isCompiled_;
}

double Input::getValue()
{
	return this->value_;
}

bool Input::isNan()
{
	return this->isNan_;
}

bool Input::isInf()
{
	return this->isInf_;
}
