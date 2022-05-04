#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	// ****************[canonical class form]****************
public:
	Dog();								// default constructor
	// 🌟 Polymorphism
	virtual ~Dog();						// destructor
	Dog(const Dog& other);				// copy constructor
	Dog& operator=(const Dog& other);	// (copy) assignment operator
	// ******************************************************
public:
	virtual void makeSound() const;
	virtual std::string getType() const;
};

#endif