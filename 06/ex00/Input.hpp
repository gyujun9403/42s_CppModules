#ifndef INPUT_HPP
#define INPUT_HPP
#include <string>
#include "InvalidInputException.hpp"

class Input
{
	// ****************[canonical class form]****************
private:
	Input(); // default constructor
public:
	virtual ~Input(); // destructor
	Input(const Input& other); // copy constructor
	Input& operator=(const Input& other); // (copy) assignment operator
	// ******************************************************
private:
	char* inputStr_;
	double value_;
	bool isNan_;
	short isInf_;

public:
	Input(char* str) throw(InvalidInputException);
	double getValue() const;
	bool isNan() const;
	bool isInf() const;
};

#endif