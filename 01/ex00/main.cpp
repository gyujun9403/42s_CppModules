//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

int main()
{
	Zombie william("William");
	william.announce();
	Zombie *leon = william.newZombie("Leon");
	leon->announce();
	leon->randomChump("Marvin");
	delete leon;
	//system("leaks ex00");
	return 0;
}