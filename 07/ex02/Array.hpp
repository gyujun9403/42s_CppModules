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
			throw(OutOfBounceException());
		return this->a_[i];
	}
	Array(unsigned int n)
	{
		//🌟 default값으로 초기화
		this->a_ = new T[n];
		this->size_ = n;
	}

	// ****************[canonical class form]****************
public:
	Array()									// default constructor
	{
		//🌟 default값으로 초기화
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
	}
	Array& operator=(const Array& other)	// (copy) assignment operator
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
		this->size_ = sizeOther;
		return *this;
	}
	// ******************************************************
};

#endif