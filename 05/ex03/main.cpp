#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat gyeon("gyeon");
	Intern someRandomIntern;
	Form* rrf;
	Form* scf;
	Form* ppf;

	try
	{
		// 🌟 edit this to test.
		gyeon.setGrade(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		return 1;
	}
	
	// 🌟 intern makes forms.
	rrf = someRandomIntern.makeForm("robotomy request", "Marvin");
	std::cout << *rrf << std::endl;
	std::cout << *dynamic_cast<RobotomyRequestForm*>(rrf) << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Jack");
	std::cout << *scf << std::endl;
	std::cout << *static_cast<ShrubberyCreationForm*>(scf) << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Leon");
	std::cout << *ppf << std::endl;
	std::cout << *static_cast<PresidentialPardonForm*>(ppf) << std::endl;

	std::cout << "---[gyeon signs and executes RobotomyRequestForm]---" << std::endl;
	try
	{
		(*dynamic_cast<RobotomyRequestForm*>(rrf)).beSigned(gyeon);
		std::cout << "\e[32m" << "sign sucess" << "\e[0m" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	try
	{
		(*dynamic_cast<RobotomyRequestForm*>(rrf)).execute(gyeon);
		std::cerr << "\e[32m" << "execute sucess" << "\e[0m" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	gyeon.signForm(*dynamic_cast<RobotomyRequestForm*>(rrf));
	gyeon.executeForm(*dynamic_cast<RobotomyRequestForm*>(rrf));
	std::cout << "----------------------------------------------------\n" << std::endl;

	std::cout << "--[gyeon signs and executes ShrubberyCreationForm]--" << std::endl;
	try
	{
		(*dynamic_cast<ShrubberyCreationForm*>(scf)).beSigned(gyeon);
		std::cout << "\e[32m" << "sign sucess" << "\e[0m" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	try
	{
		(*dynamic_cast<ShrubberyCreationForm*>(scf)).execute(gyeon);
		std::cout << "\e[32m" << "execute sucess" << "\e[0m" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	gyeon.signForm(*dynamic_cast<ShrubberyCreationForm*>(scf));
	gyeon.executeForm(*dynamic_cast<ShrubberyCreationForm*>(scf));
	std::cout << "----------------------------------------------------\n" << std::endl;

	std::cout << "--[gyeon signs and executes PresidentialPardonForm]--" << std::endl;
	try
	{
		(*dynamic_cast<PresidentialPardonForm*>(ppf)).beSigned(gyeon);
		std::cout << "\e[32m" << "sign sucess" << "\e[0m" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
	}
	try
	{
		(*dynamic_cast<PresidentialPardonForm*>(ppf)).execute(gyeon);
		std::cout << "\e[32m" << "execute sucess" << "\e[0m" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	gyeon.signForm(*dynamic_cast<PresidentialPardonForm*>(ppf));
	gyeon.executeForm(*dynamic_cast<PresidentialPardonForm*>(ppf));
	std::cout << "-----------------------------------------------------\n" << std::endl;
	free(rrf);
	free(scf);
	free(ppf);
	return 0;
}