#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat gyeon("gyeon", 10);
	ShrubberyCreationForm scf("home");
	RobotomyRequestForm rrf("factory");
	PresidentialPardonForm ppf("42");

	std::cout << scf << std::endl;

	try
	{
		std::cout << "--[sign ShrubberyCreationForm]--" << std::endl;
		gyeon.signForm(scf);
		scf.beSigned(gyeon);
		std::cout << "gyeon :Successfully signed ShrubberyCreationForm" << std::endl;
		std::cout << "\n-[execute ShrubberyCreationForm]-" << std::endl;
		gyeon.executeForm(scf);
		scf.execute(gyeon);
		std::cout << "gyeon :Successfully execute ShrubberyCreationForm" << std::endl;
		std::cout << "--------------------------------\n\n" << std::endl;
		}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "---[sign RobotomyRequestForm]---" << std::endl;
		gyeon.signForm(rrf);
		rrf.beSigned(gyeon);
		std::cout << "gyeon :Successfully signed RobotomyRequestForm" << std::endl;
		std::cout << "\n-[execute RobotomyRequestForm]-" << std::endl;
		gyeon.executeForm(rrf);
		rrf.execute(gyeon);
		std::cout << "gyeon :Successfully execute RobotomyRequestForm" << std::endl;
		std::cout << "--------------------------------\n\n" << std::endl;
		}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "--[sign PresidentialPardonForm]--" << std::endl;
		gyeon.signForm(ppf);
		ppf.beSigned(gyeon);
		std::cout << "gyeon :Successfully signed PresidentialPardonForm" << std::endl;
		std::cout << "\n-[execute PresidentialPardonForm]-" << std::endl;
		gyeon.executeForm(ppf);
		ppf.execute(gyeon);
		std::cout << "gyeon :Successfully execute PresidentialPardonForm" << std::endl;
		std::cout << "--------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}