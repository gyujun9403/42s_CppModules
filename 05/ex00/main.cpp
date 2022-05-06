#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat bc("gyeon", 120);

	try
	{
		bc.incrementGrade(3);
		std::cout << bc.getGrade() <<std::endl;
		bc.incrementGrade(30);
		std::cout << bc.getGrade() <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 1;
}