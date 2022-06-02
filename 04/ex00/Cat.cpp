#include <iostream>
#include "Cat.hpp"

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

void Cat::makeSound() const
{
	std::cout << "Cat :Meow" << std::endl;
}
