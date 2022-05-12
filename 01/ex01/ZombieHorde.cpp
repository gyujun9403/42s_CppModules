//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"
#include <stdlib.h>

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie *rt_horde;

	rt_horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		rt_horde[i].setName(name + this->numbering(i + 1));
	}
	return rt_horde;
}