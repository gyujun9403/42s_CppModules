#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	// ****************[canonical class form]****************
public:
	WrongAnimal();								// default constructor
	// 🌟 Polymorphism
	virtual ~WrongAnimal();								// destructor
	WrongAnimal(const WrongAnimal& other);			// copy constructor
	WrongAnimal& operator=(const WrongAnimal& other);	// (copy) assignment operator
	// ******************************************************

protected:
	std::string type_;
public:
	// 🌟 NOT Polymorphism
	void makeSound() const;
	std::string getType() const;
};

#endif
