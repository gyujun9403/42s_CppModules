#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	// ****************[canonical class form]****************
public:
	Intern();									// default constructor
	virtual ~Intern();							// destructor
	Intern(const Intern& other);			// copy constructor
	Intern& operator=(const Intern& other);	// (copy) assignment operator
	// ******************************************************
public:
	/* ShrubberyCreationForm : "shrubbery creation"
	* RobotomyRequestForm : "robotomy request"
	* PresidentialPardonForm : "presidential pardon" */
	Form* makeForm(const std::string formName, const std::string formTarget) const;
};

#endif