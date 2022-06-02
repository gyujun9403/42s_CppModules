#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	// ****************[canonical class form]****************
public:
	Dog(); // default constructor
	virtual ~Dog(); // destructor
	Dog(const Dog& other); // copy constructor
	Dog& operator=(const Dog& other); // (copy) assignment operator
	// ******************************************************
private:
	Brain* brain_;
public:
	virtual void makeSound() const;
	Brain& getBrain() const;
};

#endif
