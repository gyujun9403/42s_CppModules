#ifndef SCALAR_DOUBLE_HPP
#define SCALAR_DOUBLE_HPP

#include "Scalar.hpp"
#include "Input.hpp"
#include "InvalidInputException.hpp"

class Input;

class ScalarDouble : Scalar
{
	// ****************[canonical class form]****************
private:
	ScalarDouble(); // default constructor
public:
	virtual ~ScalarDouble(); // destructor
	ScalarDouble(const ScalarDouble& other); // copy constructor
	ScalarDouble& operator=(const ScalarDouble& other); // (copy) assignment operator
	// ******************************************************

private:
	double doubleScalar_;
	bool isFloat_;
	bool isOutOfDouble_;
public:
	ScalarDouble(const Input& input);
	void setScalar(const Input& input);
	// @overriding
	virtual void prtValueInfo() const;
};

#endif
