#include "InitMissingException.hpp"


initMissingException::initMissingException(std::string where)
{
	this->message_ = where + " miss initialize!";
}

initMissingException::~initMissingException() throw() {}

const char* initMissingException::what() const throw()
{
	return this->message_.c_str();
}