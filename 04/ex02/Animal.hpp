#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	// ****************[canonical class form]****************
protected:
	// 🌟
	Animal(); // default constructor
public:
	virtual ~Animal(); // destructor
	Animal(const Animal& other); // copy constructor
	Animal& operator=(const Animal& other); // (copy) assignment operator
	// ******************************************************

protected:
	std::string type_;
public:
	// 🌟 pure virtual fuction
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
