#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	// ****************[canonical class form]****************
public:
	Animal(); // default constructor
	virtual ~Animal(); // destructor
	Animal(const Animal& other); // copy constructor
	Animal& operator=(const Animal& other); // (copy) assignment operator
	// ******************************************************

protected:
	std::string type_;
public:
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
