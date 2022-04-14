//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie *rt_horde;

	rt_horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		// static_cast : c++11
		rt_horde[i].setName(name + numbering(N));
	}
	return rt_horde;
}