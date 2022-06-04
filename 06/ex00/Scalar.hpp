#ifndef SCALAR_HPP
#define SCALAR_HPP

class Scalar
{
	// ****************[canonical class form]****************
protected:
	Scalar(); // default constructor
	Scalar(const Scalar& other); // copy constructor
	Scalar& operator=(const Scalar& other); // (copy) assignment operator
	virtual ~Scalar(); // destructor
	// ******************************************************
public:
	virtual void prtValueInfo() const = 0;
};

#endif