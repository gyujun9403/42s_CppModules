#include "Input.hpp"
#include <iostream>
#include <cerrno>
#include <cmath>

Input::Input() {}

Input::~Input() {}

Input::Input(const Input& other)
: inputStr_(other.inputStr_), value_(other.value_), isNan_(other.isNan_), isInf_(other.isInf_) { }

Input& Input::operator=(const Input& other)
{
	if (this == &other)
		return *this;	
	this->inputStr_ = other.inputStr_;
	this->value_ = other.value_;
	this->isNan_ = other.isNan_;
	this->isInf_ = other.isInf_;
	return *this;
}

Input::Input(char* str) throw(std::exception)
: inputStr_(NULL), value_(0), isFloat_(false), isNan_(false), isInf_(false), isOutOfDouble_(false)
{
	char* pEnd;
	if (str == NULL || str[0] == '\0')
		throw (InvalidInputException("Input::Input(char* str)"));
	this->inputStr_ = str;
	this->value_ = std::strtod(this->inputStr_, &pEnd);
	if (errno == ERANGE)
	{
		isOutOfDouble_ = true;
	}
	if (!(pEnd[0] == '\0' || pEnd[0] == 'f' || std::isspace(pEnd[0])))
	{
	 	throw (InvalidInputException("Input::compileInput()"));
	}
	if (pEnd[0] == 'f')
	{
		this->isFloat_ = true;
		this->value_ = static_cast<double>(static_cast<float>(this->value_));
	}
	else
	{
		this->isFloat_ = false;
	}
	this->isNan_ = std::isnan(this->value_);
	this->isInf_ = std::isinf(this->value_);
}

double Input::getValue() const
{
	return this->value_;
}

bool Input::isNan() const
{
	return this->isNan_;
}

bool Input::isInf() const
{
	return this->isInf_;
}

bool Input::isFloat() const
{
	return this->isFloat_;
}

bool Input::isOutOfDouble() const
{
	return this->isOutOfDouble_;
}
