//
// Created by 연규준 on 2022/03/26.
//

#ifndef INC_01_WEAPON_HPP
#define INC_01_WEAPON_HPP

#include <string>

class Weapon {
private:
	Weapon();
	std::string type_;
public:
	Weapon(std::string type);
	const std::string& getType(void);
	void setType(std::string type);
};


#endif //INC_01_WEAPON_HPP
