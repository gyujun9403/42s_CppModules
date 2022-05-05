#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

// 가상함수와 순수 가상함수
class Animal
{
	// ****************[canonical class form]****************
protected:
	// 🌟
public:
	Animal();								// default constructor
	virtual ~Animal();						// destructor
	Animal(const Animal& other);			// copy constructor
	Animal& operator=(const Animal& other);	// (copy) assignment operator
	// ******************************************************

protected:
	std::string type_;
public:
	// 🌟 pure virtual fuction
	virtual void makeSound() const = 0;
	virtual std::string getType() const;
};

#endif