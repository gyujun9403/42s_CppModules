#include "Harl.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	int i;
	Harl h;
	bool levelFlag = false;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac != 2)
		return 1;
	for (i = 0; i < 4; i++)
	{
		if (levels[i].compare(av[1]) == 0)
			levelFlag = true;
		if (levelFlag == true)
		{
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			h.complain(levels[i]);
			std::cout << std::endl;
		}
	}
	if (i == 4 && levelFlag == false)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return 0;
}