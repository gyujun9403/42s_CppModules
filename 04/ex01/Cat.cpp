#include "Cat.hpp"

#include <iostream>

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
	// TODO:
	this->brain_ = other.brain_;
}

Cat& Cat::operator=(const Cat& other)
{
	// TODO: 자기 자신 들어오는지 확인
	this->type_ = other.type_;
	// TODO:
	this->brain_ = other.brain_;
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

Brain& Cat::getBrain() const
{
	return *brain_;
}