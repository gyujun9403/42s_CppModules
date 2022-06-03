#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	// ****************[canonical class form]****************
public:
	PresidentialPardonForm(); // default constructor
public:
	virtual ~PresidentialPardonForm(); // destructor
	PresidentialPardonForm(const PresidentialPardonForm& other); // copy constructor
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other); // (copy) assignment operator
	// ******************************************************
private:
	const static int SIGN_GRADE_ = 25;
	const static int EXER_GRADE_ = 5;
	const std::string target_;
public:
	PresidentialPardonForm(std::string target);
	std::string getTarget() const;
	virtual void execute(Bureaucrat const & executor) const throw(std::exception);
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& in);

#endif
