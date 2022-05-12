#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat gyeon("gyeon", 35);
	Intern someRandomIntern;
	Form* rrf;
	Form* scf;
	Form* ppf;

	rrf = someRandomIntern.makeForm("robotomy request", "Marvin");
	std::cout << *rrf << std::endl;
	std::cout << *dynamic_cast<RobotomyRequestForm*>(rrf) << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Jack");
	std::cout << *scf << std::endl;
	std::cout << *static_cast<ShrubberyCreationForm*>(scf) << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Leon");
	std::cout << *ppf << std::endl;
	std::cout << *static_cast<PresidentialPardonForm*>(ppf) << std::endl;
	try
	{
		gyeon.signForm(*dynamic_cast<RobotomyRequestForm*>(rrf));
		gyeon.executeForm(*dynamic_cast<RobotomyRequestForm*>(rrf));
		(*dynamic_cast<RobotomyRequestForm*>(rrf)).beSigned(gyeon);
		(*dynamic_cast<RobotomyRequestForm*>(rrf)).execute(gyeon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	free(rrf);
	free(scf);
	free(ppf);
	return 0;
}