#include "Cat.hpp"

#include <iostream>

Cat::Cat()
{
	this->type_ = "Cat";
	std::cout << "Cat() Constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "~Cat() Destructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->type_ = other.type_;
}

Cat& Cat::operator=(const Cat& other)
{
	this->type_ = other.type_;
	return *this;
}

// @overring
void Cat::makeSound() const
{
	std::cout << "Cat :Meow" << std::endl;
}

std::string Cat::getType() const
{
	return this->type_;
}
