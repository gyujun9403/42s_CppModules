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
	// TODO: 함수 호출때마다 새로 만들게됨.
	//리턴시에만 생성자가 호출되게 하여 오버헤드를 줄이게...!
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