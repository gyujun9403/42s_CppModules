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

	std::cout << "--[sign/execute ShrubberyCreationForm]--" << std::endl;
	std::cout << scf << std::endl;
	try
	{
		scf.beSigned(gyeon);
		// if exeception occured, can't run this code
		std::cout << "\e[32m" << "gyeon :Successfully signed ShrubberyCreationForm" << "\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	gyeon.signForm(scf);
	try
	{
		scf.execute(gyeon);
		std::cout << "\e[32m" << "gyeon :Successfully execute ShrubberyCreationForm" << "\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	gyeon.executeForm(scf);
	std::cout << "--------------------------------\n\n" << std::endl;
	
	std::cout << "---[sign/execute RobotomyRequestForm]---" << std::endl;
	std::cout << rrf << std::endl;
	try
	{
		rrf.beSigned(gyeon);
		std::cout << "\e[32m" << "gyeon :Successfully signed RobotomyRequestForm" << "\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	gyeon.signForm(rrf);
	try
	{
		rrf.execute(gyeon);
		std::cout << "\e[32m" << "gyeon :Successfully execute RobotomyRequestForm" << "\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	gyeon.executeForm(rrf);
	std::cout << "--------------------------------\n\n" << std::endl;

	std::cout << "--[sign/execute PresidentialPardonForm]--" << std::endl;
	std::cout << ppf << std::endl;
	try
	{
		ppf.beSigned(gyeon);
		std::cout << "\e[32m" << "gyeon :Successfully signed PresidentialPardonForm" << "\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	gyeon.signForm(ppf);
	try
	{
		ppf.execute(gyeon);
		std::cout << "\e[32m" << "gyeon :Successfully execute PresidentialPardonForm" << "\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	gyeon.executeForm(ppf);
	std::cout << "--------------------------------" << std::endl;
	

	return 0;
}
