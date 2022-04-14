//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie chump = Zombie(name);
	chump.announce();
}