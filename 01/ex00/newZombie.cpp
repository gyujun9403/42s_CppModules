//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	return new Zombie(name);
}
