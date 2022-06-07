#ifndef INIT_MISSING_EXCEPTION_HPP
#define INIT_MISSING_EXCEPTION_HPP

#include <string>

class initMissingException : public std::exception
{
private:
	std::string message_;
public:
	virtual ~initMissingException() throw();
	initMissingException(std::string where);
	virtual const char* what() const throw();
};

#endif