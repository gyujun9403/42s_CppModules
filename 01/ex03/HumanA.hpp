//
// Created by 연규준 on 2022/03/26.
//

#ifndef INC_01_HUMANA_HPP
#define INC_01_HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private:
	std::string			name_;
	// const가 없다면?
	const std::string&	weapon_;
	HumanA();
public:
	HumanA(std::string name, Weapon& weapon);
	void attack();
};


#endif //INC_01_HUMANA_HPP
