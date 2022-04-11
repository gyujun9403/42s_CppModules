//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name_ = name;
}

Zombie::~Zombie()
{
	std::cout << this->name_ << " zombie is gone." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}