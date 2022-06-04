#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "-----[create forms test]-----" << std::endl;
	Bureaucrat gyeon("gyeon");
	Form *formPtr[4];
	int i = 0;
	try
	{
		gyeon.setGrade(120);
		formPtr[i++] = new Form("form1", 80, 60);
		formPtr[i] = new Form(*formPtr[i - 1]);
		++i;
		formPtr[i++] = new Form("form2", 130, 122);
	}
	catch(const std::exception& e)
	{
		// 🌟 if exception occur in line15, i++ don't run. so, i is 2.
		for (int j = 0; j < i; j++)
			delete formPtr[j];
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	try
	{
		formPtr[3] = NULL;
		// 🌟 occcur exception.
		formPtr[3] = new Form("form4", 80, 190);
	}
	catch(const std::exception& e)
	{
		std::cout << "\e[33m" << formPtr[3] << "\e[0m" << std::endl;
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	
	std::cout << "------[prt forms info]------" << std::endl;
	std::cout << *formPtr[0] << std::endl;
	std::cout << *formPtr[1] << std::endl;
	std::cout << *formPtr[2] << std::endl;

	std::cout << "-----[gyeon signs form1]-----" << std::endl;
	std::cout << "gyeon's sign grade is " << gyeon.getGrade() << std::endl;
	std::cout << *formPtr[0] << std::endl;
	try
	{
		gyeon.signForm(*formPtr[0]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}

	std::cout << "-----[gyeon signs form2]-----" << std::endl;
	std::cout << "gyeon's sign grade is " << gyeon.getGrade() << std::endl;
	std::cout << *formPtr[2] << std::endl;
	try
	{
		gyeon.signForm(*formPtr[2]);
		(*formPtr[2]).beSigned(gyeon);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}

	std::cout << "----[copy form2 to form 1]----" << std::endl;
	*formPtr[0] = *formPtr[2];
	std::cout << *formPtr[0] <<std::endl;
	std::cout << "form1 signed? :" << (*formPtr[0]).isSigned() << std::endl;
	delete formPtr[0];
	delete formPtr[1];
	delete formPtr[2];
	return 0;
}
