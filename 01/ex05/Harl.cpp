#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	// a value of type "void (Harl::*)()" cannot be used to initialize an entity of type "void (*)()"
	//void (*funcPtr[4])(void) = {Harl::debug, Harl::info, Harl::warning, Harl::error};
	void (Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
			(this->*funcPtr[i])();
	}
}

// ref : https://junk-s.tistory.com/38