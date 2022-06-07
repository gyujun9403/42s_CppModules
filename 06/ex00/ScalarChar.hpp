#ifndef SCALAR_CHAR_HPP
#define SCALAR_CHAR_HPP

#include "Input.hpp"
#include "Scalar.hpp"
#include "InvalidInputException.hpp"
#include "InitMissingException.hpp"

class Input;

class ScalarChar: public Scalar
{
	// ****************[canonical class form]****************
private:
	ScalarChar(); // default constructor
public:
	virtual ~ScalarChar(); // destructor
	ScalarChar(const ScalarChar& other); // copy constructor
	ScalarChar& operator=(const ScalarChar& other); // (copy) assignment operator
	// ******************************************************

private:
	char charValue_;
public:
	ScalarChar(const Input& input);
	void setValue(const Input& input);
	// @overriding
	virtual void prtValueInfo() const;
};

#endif