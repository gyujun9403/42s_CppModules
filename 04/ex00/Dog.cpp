#include "Dog.hpp"

#include <iostream>

Dog::Dog()
{
	this->type_ = "Dog";
	std::cout << "Dog() Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "~Dog() Destructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->type_ = other.type_;
}

Dog& Dog::operator=(const Dog& other)
{
	this->type_ = other.type_;
	return *this;
}

// @overring
void Dog::makeSound() const
{
	std::cout << "Dog :Woof" << std::endl;
}

std::string Dog::getType() const
{
	return this->type_;
}
