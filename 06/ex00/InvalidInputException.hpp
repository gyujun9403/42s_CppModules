#ifndef INVALID_INPUT_EXCEPTION_HPP
#define INVALID_INPUT_EXCEPTION_HPP

#include <string>

class InvalidInputException : public std::exception
{
private:
	std::string message_;
public:
	virtual ~InvalidInputException() throw();
	InvalidInputException(std::string where);
	virtual const char* what() const throw();
};

#endif