#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	// ****************[canonical class form]****************
public:
	RobotomyRequestForm(); // default constructor
public:
	virtual ~RobotomyRequestForm(); // destructor
	RobotomyRequestForm(const RobotomyRequestForm& other); // copy constructor
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other); // (copy) assignment operator
	// ******************************************************
private:
	const static int SIGN_GRADE_ = 72;
	const static int EXER_GRADE_ = 45;
	const std::string target_;
public:
	RobotomyRequestForm(std::string target);
	std::string getTarget() const;
	virtual void execute(Bureaucrat const & executor) const throw(std::exception);
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& in);

#endif
