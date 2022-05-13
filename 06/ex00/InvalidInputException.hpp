#ifndef INVALID_INPUT_EXCEPTION_HPP
#define INVALID_INPUT_EXCEPTION_HPP

#include <string>

class InvalidInputException
{
private:
	std::string message_;
public:
	InvalidInputException(std::string where);
	virtual ~InvalidInputException() throw();
	virtual const char* what() const throw();
};

#endif