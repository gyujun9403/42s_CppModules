#include "initializeMissingException.hpp"


initializeMissingException::initializeMissingException(std::string where)
{
	//this->message_ = "["+ where + "] Invalid input.";
	this->message_ = where + " miss initialize!"
}

initializeMissingException::~initializeMissingException() throw() {}

const char* initializeMissingException::what() const throw()
{
	return this->message_.c_str();
}