//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

int main()
{
	Zombie william("William");
	Zombie leon = william.newZombie("Leon");
	leon.randomChump("Marvin");
	delete leon;
	return 0;
}