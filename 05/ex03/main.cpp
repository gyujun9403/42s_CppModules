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
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		return 1;
	}
	
	// 🌟 intern makes forms.
	// TODO:null defence
	rrf = someRandomIntern.makeForm("robotomy request", "Marvin");
	std::cout << *rrf << std::endl;
	std::cout << *dynamic_cast<RobotomyRequestForm*>(rrf) << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Jack");
	std::cout << *scf << std::endl;
	std::cout << *dynamic_cast<ShrubberyCreationForm*>(scf) << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Leon");
	std::cout << *ppf << std::endl;
	std::cout << *dynamic_cast<PresidentialPardonForm*>(ppf) << std::endl;

	std::cout << "---[gyeon signs and executes RobotomyRequestForm]---" << std::endl;
	gyeon.signForm(*dynamic_cast<RobotomyRequestForm*>(rrf));
	gyeon.executeForm(*dynamic_cast<RobotomyRequestForm*>(rrf));
	std::cout << "----------------------------------------------------\n" << std::endl;

	std::cout << "--[gyeon signs and executes ShrubberyCreationForm]--" << std::endl;
	gyeon.signForm(*dynamic_cast<ShrubberyCreationForm*>(scf));
	gyeon.executeForm(*dynamic_cast<ShrubberyCreationForm*>(scf));
	std::cout << "----------------------------------------------------\n" << std::endl;

	std::cout << "--[gyeon signs and executes PresidentialPardonForm]--" << std::endl;
	gyeon.signForm(*dynamic_cast<PresidentialPardonForm*>(ppf));
	gyeon.executeForm(*dynamic_cast<PresidentialPardonForm*>(ppf));
	std::cout << "-----------------------------------------------------\n" << std::endl;
	
	delete rrf;
	delete scf;
	delete ppf;
	return 0;
}