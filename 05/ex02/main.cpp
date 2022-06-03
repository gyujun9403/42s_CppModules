#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat gyeon("gyeon");
	ShrubberyCreationForm scf("home");
	RobotomyRequestForm rrf("factory");
	PresidentialPardonForm ppf("42");
	try
	{
		// 🌟 To test, edit this.
		gyeon.setGrade(70);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << scf << std::endl;

	std::cout << "--[sign ShrubberyCreationForm]--" << std::endl;
	try
	{
		gyeon.signForm(scf);
		scf.beSigned(gyeon);
		// if exeception occured, can't run this code
		std::cout << "gyeon :Successfully signed ShrubberyCreationForm" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\n-[execute ShrubberyCreationForm]-" << std::endl;
	try
	{
		gyeon.executeForm(scf);
		scf.execute(gyeon);
		std::cout << "gyeon :Successfully execute ShrubberyCreationForm" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "--------------------------------\n\n" << std::endl;
	
	std::cout << "---[sign RobotomyRequestForm]---" << std::endl;
	try
	{
		gyeon.signForm(rrf);
		rrf.beSigned(gyeon);
		std::cout << "gyeon :Successfully signed RobotomyRequestForm" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\n-[execute RobotomyRequestForm]-" << std::endl;
	try
	{
		gyeon.executeForm(rrf);
		rrf.execute(gyeon);
		std::cout << "gyeon :Successfully execute RobotomyRequestForm" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "--------------------------------\n\n" << std::endl;

	std::cout << "--[sign PresidentialPardonForm]--" << std::endl;
	try
	{
		gyeon.signForm(ppf);
		ppf.beSigned(gyeon);
		std::cout << "gyeon :Successfully signed PresidentialPardonForm" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "\n-[execute PresidentialPardonForm]-" << std::endl;

	try
	{
		gyeon.executeForm(ppf);
		ppf.execute(gyeon);
		std::cout << "gyeon :Successfully execute PresidentialPardonForm" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	std::cout << "--------------------------------" << std::endl;
	

	return 0;
}
