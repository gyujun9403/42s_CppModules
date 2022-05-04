#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal()
{
	this->type_ = "WrongAnimal";
	std::cout << "WrongAnimal() Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "~WrongAnimal() Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type_ = other.type_;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type_ = other.type_;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal :*#!^$W^#@^#$!?%@?#^$#&$^%@$#*@" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type_;
}