//
// Created by 연규준 on 2022/03/26.
//

#ifndef INC_01_HUMANB_HPP
#define INC_01_HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	std::string	name_;
	// 🌟 difference with bHumanA
	Weapon	weapon_;
	HumanB();
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon& weapon);
	void setWeapon(Weapon& weapon);
	void attack();
};

#endif //INC_01_HUMANB_HPP
