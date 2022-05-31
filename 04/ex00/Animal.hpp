#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	// ****************[canonical class form]****************
public:
	Animal();								// default constructor
	// 🌟 Polymorphism
	virtual ~Animal();								// destructor
	Animal(const Animal& other);			// copy constructor
	Animal& operator=(const Animal& other);	// (copy) assignment operator
	// ******************************************************

protected:
	std::string type_;
public:
	// 🌟 Polymorphism
	virtual void makeSound() const;
	//TODO: virtual일 필요 없고, 여기서 있으면 cat dog에서 따로 선언할 필요도 없음
	virtual std::string getType() const;
};

#endif