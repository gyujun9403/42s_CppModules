#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP


#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	// ****************[canonical class form]****************
public:
	ShrubberyCreationForm(); // default constructor
public:
	virtual ~ShrubberyCreationForm(); // destructor
	ShrubberyCreationForm(const ShrubberyCreationForm& other); // copy constructor
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); // (copy) assignment operator
	// ******************************************************
private:
	const static int SIGN_GRADE_ = 145;
	const static int EXER_GRADE_ = 137;
	const std::string target_;
public:
	ShrubberyCreationForm(std::string target);
	std::string getTarget() const;
	virtual void execute(Bureaucrat const & executor) const throw(std::exception);
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& in);

#endif
