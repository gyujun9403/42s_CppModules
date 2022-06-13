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
	Array(unsigned int n)
	{
		//🌟 init to zero
		this->a_ = new T[n]();
		this->size_ = n;
	}
	unsigned int size() const
	{
		return this->size_;
	}
	// if not const func, error occur like below.
	/*
	candidate function not viable: 'this' argument has type 'const
      Array<std::__1::basic_string<char> >', but method is not marked const
        T& operator[](unsigned int i) throw(std::exception)
           ^
	*/
	T& operator[](unsigned int i) const throw(std::exception)
	{
		if (i >= this->size_)
		{
			throw(OutOfBounceException());
		}
		return this->a_[i];
	}

	// ****************[canonical class form]****************
public:
	Array()									// default constructor
	{
		a_ = new T[0]();
		size_ = 0;
	}
	virtual ~Array()						// destructor
	{
		if (a_ != NULL)
		{
			delete[] a_;
		}
	}
	Array(const Array& other)				// copy constructor
	{		
		this->size_ = other.size();
		a_ = new T[this->size_]();
		for (unsigned int i = 0; i < this->size_; i++)
		{
			a_[i] = other[i];
		}
	}
	Array& operator=(const Array& other)	// (copy) assignment operator
	{
		if (this == &other)
		{
			return *this;
		}
		else
		{
			if (this->a_ != NULL)
			{
				delete[] a_;
			}
			this->size_ = other.size();
			a_ = new T[this->size_]();
			for (unsigned int i = 0; i < this->size_; i++)
			{
				a_[i] = other[i];
			}
			return *this;
		}
	}
	// ******************************************************
};

#endif