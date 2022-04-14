//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"
#define NUM_OF_ZOMBIES_IN_HORDE	10

int main()
{
	Zombie	zombie_host("leon");
	Zombie* horde = zombie_host.zombieHorde(3, "zombie");
	for (int i = 0; i < NUM_OF_ZOMBIES_IN_HORDE; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}