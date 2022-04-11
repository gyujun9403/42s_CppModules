//
// Created by 연규준 on 2022/03/26.
//

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *rt_horde;

	rt_horde = new Zombie[N];
	for (int i; i < N; i++) {
		// static_cast : c++11
		rt_horde[i] = Zombie(name.append((char)(i + '0')));
	}
	return rt_horde;
}