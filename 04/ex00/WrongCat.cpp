#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat()
{
	this->type_ = "WrongCat";
	std::cout << "WrongCat() Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "~WrongCat() Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	this->type_ = other.type_;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	this->type_ = other.type_;
	return *this;
}

// @overring
void WrongCat::makeSound() const
{
	std::cout << "WrongCat :Meow" << std::endl;
}

std::string WrongCat::getType() const
{
	return this->type_;
}
