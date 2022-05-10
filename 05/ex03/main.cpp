#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Form* rrf;
	Form* scf;
	Form* ppf;

	rrf = someRandomIntern.makeForm("robotomy request", "Marvin");
	std::cout << *rrf << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Jack");
	std::cout << *scf << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Leon");
	std::cout << *ppf << std::endl;
	free(rrf);
	free(scf);
	free(ppf);
	return 0;
}