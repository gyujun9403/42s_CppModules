#ifndef SCALAR_DOUBLE_HPP
#define SCALAR_DOUBLE_HPP

#include "Scalar.hpp"
#include "Input.hpp"
#include "InvalidInputException.hpp"
#include "InitMissingException.hpp"

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
public:
	ScalarDouble(Input& input);
	void setScalar(Input& input);
	// @overriding
	virtual void prtValueInfo() const;
};

#endif
