#ifndef SCALAR_FLOAT_HPP
#define SCALAR_FLOAT_HPP

#include "Scalar.hpp"
#include "Input.hpp"
#include "InvalidInputException.hpp"
#include "InitMissingException.hpp"

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
public:
	ScalarFloat(Input& input);
	void setScalar(Input& input);
	// @overriding
	virtual void prtValueInfo() const;
};

#endif
