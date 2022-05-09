#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat gyeon("gyeon", 120);
	Bureaucrat temp1(gyeon);
	Bureaucrat temp2 = gyeon;
	Bureaucrat marvin("marvin", 10);
	try
	{
		Bureaucrat gyeonFalse("gyeon", 170);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		marvin = gyeon;

		std::cout << "----------[copy test]----------" <<std::endl;
		std::cout << "gyeon :" << gyeon <<std::endl;
		std::cout << "temp1 :" << temp1 <<std::endl;
		std::cout << "temp2 :" << temp2 <<std::endl;
		std::cout << "marvin :" << marvin <<std::endl;
		std::cout << "---[increment/decrement test]---" <<std::endl;
		std::cout << "{gyeon :increment 3}"<<std::endl;
		gyeon.incrementGrade(3);
		std::cout << gyeon <<std::endl;
		std::cout << "{gyeon :increment 30}"<<std::endl;
		gyeon.incrementGrade(30);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << gyeon <<std::endl;
		std::cout << "{temp1 :increment 5}"<<std::endl;
		temp1.incrementGrade(5);
		std::cout << temp1 <<std::endl;
		std::cout << "{marvin :increment 3}"<<std::endl;
		marvin.incrementGrade(31);
		std::cout << marvin <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 1;
}