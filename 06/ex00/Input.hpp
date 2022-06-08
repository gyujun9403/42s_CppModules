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
	bool isFloat_;
	bool isNan_;
	bool isInf_;
	bool isOutOfDouble_;

public:
	Input(char* str) throw(std::exception);
	double getValue() const;
	bool isNan() const;
	bool isInf() const;
	bool isFloat() const;
	bool isOutOfDouble() const;
};

#endif