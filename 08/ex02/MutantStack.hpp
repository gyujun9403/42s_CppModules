#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	// ****************[canonical class form]****************
public:
	MutantStack() {} // default constructor
	virtual ~MutantStack() {} // destructor
	MutantStack(const MutantStack& other) // copy constructor
	: std::stack<T>(static_cast<std::stack<T> >(other)) {}
	MutantStack& operator=(const MutantStack& other) // (copy) assignment operator
	{
		this->c = other.c;
		return *this;
	}
	// ******************************************************
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()  throw()
	{
		return this->c.begin();
	}
	iterator end() throw()
	{
		return this->c.end();
	}
};

#endif