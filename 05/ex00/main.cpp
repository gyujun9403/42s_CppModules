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
	catch(const std::exception& e)
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
	std::cout << "--[increment/decrement test]" <<std::endl;
	std::cout << "{gyeon :increment 3}"<<std::endl;
	try
	{
		gyeon.incrementGrade(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << gyeon <<std::endl;

	std::cout << "{gyeon :increment 30}"<<std::endl;
	try
	{
		// 🌟 occur exception.
		gyeon.incrementGrade(30);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << gyeon <<std::endl;
	
	std::cout << "{temp1 :increment 5}"<<std::endl;
	try
	{
		temp1.incrementGrade(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << temp1 <<std::endl;
		
	std::cout << "{marvin :increment 31}"<<std::endl;
	try
	{
		marvin.incrementGrade(31);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\t" << marvin <<std::endl;

	return 0;
}