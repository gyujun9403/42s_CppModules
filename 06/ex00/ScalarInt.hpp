#ifndef SCALAR_INT_HPP
#define SCALAR_INT_HPP

#include "Scalar.hpp"
#include "Input.hpp"
#include "InvalidInputException.hpp"

class Input;

class ScalarInt : Scalar
{
	// ****************[canonical class form]****************
private:
	ScalarInt(); // default constructor
public:
	virtual ~ScalarInt(); // destructor
	ScalarInt(const ScalarInt& other); // copy constructor
	ScalarInt& operator=(const ScalarInt& other); // (copy) assignment operator
	// ******************************************************

private:
	int intScalar_;
	bool isOutOfDouble_;
public:
	ScalarInt(const Input& input);
	void setScalar(const Input& input);
	// @overriding
	virtual void prtValueInfo() const;
};

#endif
