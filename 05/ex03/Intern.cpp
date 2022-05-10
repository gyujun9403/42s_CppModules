#include <iostream>
#include "Intern.hpp"

Intern::Intern() { ;}

Intern::~Intern() { ;}

Intern::Intern(const Intern& other)
{
	static_cast<void>(other);
}

Intern& Intern::operator=(const Intern& other)
{
	static_cast<void>(other);
	return *this;
}

Form* retShrubberyCreationForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form* retRobotomyRequestForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

Form* retPresidentialPardonForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const std::string formName, const std::string formTarget) const
{
	Form* (*allForms[3])(const std::string target)
		= {retShrubberyCreationForm, retRobotomyRequestForm, retPresidentialPardonForm};
	static std::string formNameSet[3]
		= {"shrubbery creation", "robotomy request", "presidential pardon"};
	static std::string formSet[3]
		= {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (formNameSet[i].compare(formName) == 0)
		{
			std::cout << "Intern creates " << formSet[i] << std::endl;
			return allForms[i](formTarget);
		}
	}
	std::cerr << "Intern can't create Form. Allowed form names are below." << std::endl
		<< "  ShrubberyCreationForm : \"shrubbery creation\"" << std::endl
		<< "  RobotomyRequestForm : \"robotomy request\"" << std::endl
		<< "  PresidentialPardonForm : \"presidential pardon\"" << std::endl;
	return NULL;
}