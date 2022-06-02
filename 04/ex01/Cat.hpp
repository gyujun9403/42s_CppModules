#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	// ****************[canonical class form]****************
public:
	Cat();								// default constructor
	virtual ~Cat();						// destructor
	Cat(const Cat& other);				// copy constructor
	Cat& operator=(const Cat& other);	// (copy) assignment operator
	// ******************************************************
private:
	Brain* brain_;
public:
	virtual void makeSound() const;
	Brain& getBrain() const;
};

#endif
