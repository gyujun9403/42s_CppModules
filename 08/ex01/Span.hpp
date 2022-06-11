#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	// ****************[canonical class form]****************
private:
	Span(); // default constructor
public:
	virtual ~Span(); // destructor
	Span(const Span& other); // copy constructor
	Span& operator=(const Span& other); // (copy) assignment operator
	// ******************************************************
private:
    unsigned int N_;
    std::vector<int> vecData_;
    bool isSorted_;
    typedef std::vector<int>::iterator iterVec;
public:
    Span(unsigned int N);
    void addNumber(int element) throw(std::exception);
    unsigned int shortestSpan() throw(std::exception);
    unsigned int longestSpan() throw(std::exception);
};

#endif