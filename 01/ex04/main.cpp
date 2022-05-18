#include <iostream>
#include "Replacer.hpp"

int main(int ac, char *av[])
{
	std::string fName;
	std::string s1, s2;
	if (ac < 4)
	{
		return 1;
	}
	fName.assign(av[1]);
	s1.assign(av[2]);
	s2.assign(av[3]);
	if (s1.find("\n") != std::string::npos || s2.find("\n") != std::string::npos)
	{
		std::cout << "Not using \'\\n\'in string." << std::endl;
		return 1;
	}
	Replacer rpl(fName);
	
	if (rpl.isReplacerUsable() == true)
	{
		rpl.replace(s1, s2);
		rpl.closeFiles();
	}
	return (0);
}