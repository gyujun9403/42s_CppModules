//
// Created by 연규준 on 2022/03/26.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type_ = type;
}

const std::string& Weapon::getType(void)
{
	return this->type_;
}
void Weapon::setType(std::string type)
{
	this->type_ = type;
}