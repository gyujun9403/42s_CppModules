#ifndef DATA_HPP
#define DATA_HPP
#include <string>
#include <exception>

class Data
{
	// ****************[canonical class form]****************
private:
	Data();								// default constructor
public:
	virtual ~Data();					// destructor
	Data(const Data& other);			// copy constructor
	Data& operator=(const Data& other);	// (copy) assignment operator
	// ******************************************************
private:
	bool isCompiled_;
	char* inputStr_;
	double value_;
	// -1 : error, 
	bool isNan_;
	short isInf_;
	class InvalidInputException : std::exception
	{
	private:
		virtual const char* what() const throw();
	};

public:
	Data(char* str) throw(std::exception);
	void compileData() throw(std::exception);
};

#endif