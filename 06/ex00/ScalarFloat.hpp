#ifndef SCALAR_FLOAT_HPP
#define SCALAR_FLOAT_HPP

#include "Scalar.hpp"
#include "Input.hpp"
#include "InvalidInputException.hpp"

class Input;

class ScalarFloat : Scalar
{
	// ****************[canonical class form]****************
private:
	ScalarFloat(); // default constructor
public:
	virtual ~ScalarFloat(); // destructor
	ScalarFloat(const ScalarFloat& other); // copy constructor
	ScalarFloat& operator=(const ScalarFloat& other); // (copy) assignment operator
	// ******************************************************

private:
	float floatScalar_;
	bool isOutOfDouble_;
public:
	ScalarFloat(const Input& input);
	void setScalar(const Input& input);
	// @overriding
	virtual void prtValueInfo() const;
};

#endif
