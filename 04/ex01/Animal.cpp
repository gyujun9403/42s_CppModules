#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal() Constructor called" << std::endl;
	this->type_ = "Animal";
}

Animal::~Animal()
{
	std::cout << "~Animal() Destructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->type_ = other.type_;
}

Animal& Animal::operator=(const Animal& other)
{
	this->type_ = other.type_;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal :*#!^$W^#@^#$!?%@?#^$#&$^%@$#*@" << std::endl;
}

std::string Animal::getType() const
{
	return this->type_;
}
