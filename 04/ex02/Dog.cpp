#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog() Constructor called" << std::endl;
	this->type_ = "Dog";
	this->brain_ = new Brain();
}

Dog::~Dog()
{
	std::cout << "~Dog() Destructor called" << std::endl;
	delete brain_;
}

Dog::Dog(const Dog& other)
{
	this->type_ = other.type_;
	*this->brain_ = *other.brain_;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return *this;
	this->type_ = other.type_;
	*this->brain_ = *other.brain_;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog :Woof" << std::endl;
}

Brain& Dog::getBrain() const
{
	return *brain_;
}
