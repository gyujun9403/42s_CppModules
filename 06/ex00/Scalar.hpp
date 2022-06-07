#ifndef SCALAR_HPP
#define SCALAR_HPP

#include "Input.hpp"

class Input;

class Scalar
{
	// ****************[canonical class form]****************
protected:
	Scalar(); // default constructor
	Scalar(const Scalar& other); // copy constructor
	Scalar& operator=(const Scalar& other); // (copy) assignment operator
	virtual ~Scalar(); // destructor
	// ******************************************************
private:
	double orgScalar_;
protected:
	bool isNan_;
	short isInf_;
	Scalar(const Input& input);
	void setScalar(const Input& input);
	double getOrgValue() const;
public:
	virtual void prtValueInfo() const = 0;
};

#endif