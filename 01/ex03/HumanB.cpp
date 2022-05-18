//
// Created by 연규준 on 2022/03/26.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: weapon_("His hands")
{
	this->name_ = name;
}

HumanB::HumanB(std::string name, Weapon& weapon)
: weapon_(weapon.getType())
{
	this->name_ = name;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon_.setType(weapon.getType());
}

void HumanB::attack()
{
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}