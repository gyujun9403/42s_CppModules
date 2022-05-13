#include "Input.hpp"
#include <iostream>
#include <cmath>

Input::Input()
{
	this->isCompiled_ = false;
}

Input::~Input() { ;}

Input::Input(const Input& other)
{
	this->isCompiled_ = other.isCompiled_;
	this->inputStr_ = other.inputStr_;
	this->value_ = other.value_;
	this->isNan_ = other.isNan_;
	this->isInf_ = other.isInf_;
	this->isCompiled_ = other.isCompiled_;
}

Input& Input::operator=(const Input& other)
{
	this->inputStr_ = other.inputStr_;
	this->value_ = other.value_;
	this->isNan_ = other.isNan_;
	this->isInf_ = other.isInf_;
	this->isCompiled_ = other.isCompiled_;
	return *this;
}

Input::Input(char* str) throw(InvalidInputException)
{
	if (str == NULL || str[0] == '\0')
		throw (InvalidInputException("Input::Input(char* str)"));
	this->inputStr_ = str;
}

void Input::compileInput() throw(InvalidInputException)
{
	char* pEnd;

	this->value_ = std::strtod(this->inputStr_, &pEnd);
	if (!(pEnd[0] == '\0' || pEnd[0] == 'f' || std::isspace(pEnd[0])))
	 	throw (InvalidInputException("Input::compileInput()"));
	this->isNan_ = std::isnan(this->value_);
	this->isInf_ = std::isinf(this->value_);
	this->isCompiled_ = true;
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
