#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	// ****************[canonical class form]****************
public:
	WrongCat(); // default constructor
	// 🌟 If not virtual, all of destructor do not be called.
	virtual ~WrongCat(); // destructor
	WrongCat(const WrongCat& other); // copy constructor
	WrongCat& operator=(const WrongCat& other);	// (copy) assignment operator
	// ******************************************************
public:
	// 🌟 NOT Polymorphism
	void makeSound() const;
};

#endif
