#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

// func using T : declare here
// func not using T : declare cpp file?? <- Nope.
template<typename T>
class Array
{
private:
	T* a_;
	unsigned int size_;
	// not public Inheritance, abort occur
	//libc++abi.dylib: terminating with unexpected exception of type Array<int>::OutOfBounceException
	//[1]    21806 abort      ./ex02
	class OutOfBounceException: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "[exception] Out of bonce exception occur.";
		}
	};
public:
	unsigned int size() const
	{
		return this->size_;
	}
	T& operator[](unsigned int i) throw(std::exception)
	{
		if (i >= this->size_)
			throw(OutOfBounceException());
		return this->a_[i];
	}
	Array(unsigned int n)
	{
		this->a_ = new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			this->a_[i] = 0;
		}
		this->size_ = n;
	}

	// ****************[canonical class form]****************
public:
	Array()									// default constructor
	{
		a_ = new T[0];
		size_ = 0;
	}
	virtual ~Array()						// destructor
	{
		// 🌟
		if (a_ != NULL)
			delete[] a_;
	}
	Array(const Array& other)				// copy constructor
	{
		unsigned int sizeOther;
		if (this->a_ != NULL)
			delete[] a_;
		sizeOther = other.size();
		a_ = new T[sizeOther];
		for (unsigned int i = 0; i < sizeOther; i++)
		{
			a_[i] = other[i];
		}
	}
	Array& operator=(const Array& other)	// (copy) assignment operator
	{
		unsigned int sizeOther;

		if (this->a_ != NULL)
			delete[] a_;
		sizeOther = other.size();
		a_ = new T[sizeOther];
		for (int i = 0; i < sizeOther; i++)
		{
			a_[i] = other[i];
		}
		return *this;
	}
	// ******************************************************
};

#endif