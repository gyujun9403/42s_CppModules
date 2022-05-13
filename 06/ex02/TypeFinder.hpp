#ifndef TYPE_FINDER_HPP
#define TYPE_FINDER_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class TypeFinder
{
	// ****************[canonical class form]****************
public:
	TypeFinder();									// default constructor
	virtual ~TypeFinder();							// destructor
	TypeFinder(const TypeFinder& other);			// copy constructor
	TypeFinder& operator=(const TypeFinder& other);	// (copy) assignment operator
	// ******************************************************

public:
	static Base * generate(void);
	static void identify(Base* p);
	static void identify(Base& p);
};

#endif