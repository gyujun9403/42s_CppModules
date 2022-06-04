#ifndef SCALAR_CHAR_HPP
#define SCALAR_CHAR_HPP

#include "Input.hpp"
#include "Scalar.hpp"
#include "InvalidInputException.hpp"

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
	char scalar_;
	Input* input_;
public:
	ScalarChar(Input& input) throw(InvalidInputException);
	void setScalar(Input& input) throw(InvalidInputException);
	// @overriding
	virtual void prtValueInfo() const;
};

#endif