#include "InvalidInputException.hpp"


InvalidInputException::InvalidInputException(std::string where)
{
	this->message_ = "["+ where + "] Invalid input.";
}

InvalidInputException::~InvalidInputException() throw()
{
	;
}

const char* InvalidInputException::what() const throw()
{
	return this->message_.c_str();
}