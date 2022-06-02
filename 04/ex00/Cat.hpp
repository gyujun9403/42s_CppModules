#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	// ****************[canonical class form]****************
public:
	Cat(); // default constructor
	// 🌟 Polymorphism
	virtual ~Cat(); // destructor
	Cat(const Cat& other); // copy constructor
	Cat& operator=(const Cat& other); // (copy) assignment operator
	// ******************************************************
public:
	virtual void makeSound() const;
};

#endif
