//
// Created by 연규준 on 2022/03/26.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name_ = name;
	this->weapon_ = "His hands";
}

HumanB::HumanB(std::string name, Weapon& weapon)
{
	this->name_ = name;
	this->weapon_ = weapon.getType();
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon_ = weapon.getType();
}

void HumanB::attack()
{
	std::cout << name_ << " attacks with his " << weapon_ << std::endl;
}