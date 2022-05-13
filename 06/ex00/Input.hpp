#ifndef INPUT_HPP
#define INPUT_HPP
#include <string>
#include "InvalidInputException.hpp"

class Input
{
	// ****************[canonical class form]****************
private:
	Input();								// default constructor
public:
	virtual ~Input();					// destructor
	Input(const Input& other);			// copy constructor
	Input& operator=(const Input& other);	// (copy) assignment operator
	// ******************************************************
private:
	bool isCompiled_;
	char* inputStr_;
	double value_;
	// -1 : error, 
	bool isNan_;
	short isInf_;

public:
	Input(char* str) throw(InvalidInputException);
	void compileInput() throw(InvalidInputException);
	bool isComiled();
	double getValue();
	bool isNan();
	bool isInf();
};

#endif