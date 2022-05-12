#include "Data.hpp"
#include <cmath>
//std::atof, std::strtod
Data::Data()
{
	this->isCompiled_ = false;
}

Data::~Data() { ;}

Data::Data(const Data& other)
{
	this->isCompiled_ = other.isCompiled_;
	this->inputStr_ = other.inputStr_;
	this->value_ = other.value_;
	this->isNan_ = other.isNan_;
	this->isInf_ = other.isInf_;
	this->isCompiled_ = other.isCompiled_;
}

Data& Data::operator=(const Data& other)
{
	this->inputStr_ = other.inputStr_;
	this->value_ = other.value_;
	this->isNan_ = other.isNan_;
	this->isInf_ = other.isInf_;
	this->isCompiled_ = other.isCompiled_;
	return *this;
}

const char* Data::InvalidInputException::what() const throw()
{
	return "Invalid input.";
}

Data::Data(char* str) throw(std::exception)
{
	if (str == NULL || str[0] == '\0')
		throw (InvalidInputException());
	this->inputStr_ = str;
}

void Data::compileData() throw(std::exception)
{
	char* pEnd;

	this->value_ = std::strtod(this->inputStr_, &pEnd);
	if (pEnd[0] != '\0' || pEnd[0] != 'f' || !std::isspace(pEnd[0]))
		throw (InvalidInputException());
	this->isNan_ = std::isnan(this->value_);
	this->isInf_ = std::isinf(this->value_);
	this->isCompiled_ = true;
}