//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

Zombie::Zombie(){;}

Zombie::Zombie(std::string name)
{
	this->name_ = name;
}

Zombie::~Zombie()
{
	std::cout << this->name_ << " zombie is gone." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name_ = name;
}

void Zombie::announce()
{
	std::cout << this->name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::numbering(int i)
{
	std::string ret("");

	if (i < 10)
		ret = ret + (char)i;
	else
		ret = (ret + numbering(i / 10) + (char)(i % 10));
	return (ret);
}