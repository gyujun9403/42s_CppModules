#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat() Constructor called" << std::endl;
	this->type_ = "Cat";
	this->brain_ = new Brain();
}

Cat::~Cat()
{
	std::cout << "~Cat() Destructor called" << std::endl;
	delete brain_;
}

Cat::Cat(const Cat& other)
{
	this->type_ = other.type_;
	*this->brain_ = *other.brain_;
}

Cat& Cat::operator=(const Cat& other)
{
	
		return *this;
	this->type_ = other.type_;
	*this->brain_ = *other.brain_;
	return *this;
}

// @overring
void Cat::makeSound() const
{
	std::cout << "Cat :Meow" << std::endl;
}

Brain& Cat::getBrain() const
{
	return *brain_;
}
