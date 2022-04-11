//
// Created by 연규준 on 2022/03/26.
//

#ifndef INC_01_ZOMBIE_HPP
#define INC_01_ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	Zombie();
	std::string name_;
public:
	Zombie(std::string name);
	void announce();
	Zombie* zombieHorde(int N, std::string name);
	~Zombie();
};


#endif //INC_01_ZOMBIE_HPP
