#ifndef INVALID_INPUT_EXCEPTION_HPP
#define INVALID_INPUT_EXCEPTION_HPP

#include <string>

class initializeMissingException : public std::exception
{
private:
	std::string message_;
public:
	virtual ~initializeMissingException() throw();
	initializeMissingException(std::string where);
	virtual const char* what() const throw();
};

#endif