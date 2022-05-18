//
// Created by 연규준 on 2022/03/26.
//

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_(weapon)
{
	this->name_ = name;
	//this->weapon_ = weapon.getType();
}

void HumanA::attack()
{
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}