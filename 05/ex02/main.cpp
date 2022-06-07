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
	PresidentialPardonForm ppf("human");
	try
	{
		// 🌟 To test, edit this.
		gyeon.setGrade(72);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		return 1;
	}

	std::cout << "--------------[sign/execute ShrubberyCreationForm]--------------" << std::endl;
	std::cout << scf << std::endl;
	gyeon.signForm(scf);
	gyeon.executeForm(scf);
	std::cout << "----------------------------------------------------------------\n\n" << std::endl;
	
	std::cout << "---------------[sign/execute RobotomyRequestForm]---------------" << std::endl;
	std::cout << rrf << std::endl;
	gyeon.signForm(rrf);
	gyeon.executeForm(rrf);
	std::cout << "----------------------------------------------------------------\n\n" << std::endl;

	std::cout << "-------------[sign/execute PresidentialPardonForm]-------------" << std::endl;
	std::cout << ppf << std::endl;
	gyeon.signForm(ppf);
	gyeon.executeForm(ppf);
	std::cout << "---------------------------------------------------------------" << std::endl;

	return 0;
}
