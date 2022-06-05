#include "Bureaucrat.hpp"
#include <iostream>

int main()
{	
	std::cout << "----------[test 1]----------" <<std::endl;
	Bureaucrat gyeon("gyeon");
	Bureaucrat marvin("marvin");
	try
	{
		gyeon.setGrade(120);
		marvin.setGrade(10);
		// 🌟 occur exception.
		marvin.setGrade(151);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	// 🌟 copy constructor
	Bureaucrat temp1(gyeon);
	Bureaucrat temp2 = gyeon;
	// 🌟 assignment operator
	marvin = gyeon;

	std::cout << gyeon <<std::endl;
	std::cout << temp1 <<std::endl;
	std::cout << temp2 <<std::endl;
	std::cout << marvin <<std::endl;

	std::cout << "----------[test 2]----------" <<std::endl;
	std::cout << "{gyeon :down 3 grade}"<<std::endl;
	try
	{
		gyeon.downGrade(3);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << gyeon <<std::endl;

	std::cout << "{gyeon :down 30 grade}"<<std::endl;
	try
	{
		// 🌟 occur exception.
		gyeon.downGrade(30);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << gyeon <<std::endl;
	
	std::cout << "{gyeon :down 5 grade}"<<std::endl;
	try
	{
		gyeon.downGrade(5);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << gyeon <<std::endl;

	std::cout << "{gyeon :up 18 grade}"<<std::endl;
	try
	{
		gyeon.upGrade(18);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << gyeon <<std::endl;

	std::cout << "{gyeon :up 110 grade}"<<std::endl;
	try
	{
		gyeon.upGrade(110);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << gyeon <<std::endl;
	return 0;
}
