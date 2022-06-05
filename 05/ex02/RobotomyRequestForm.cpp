#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::~RobotomyRequestForm() {}

// Super class constructor explicit call
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: Form(other.getName(), other.getSignGrade(), other.getExecGrade()), target_(other.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	static_cast<void>(other);
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", SIGN_GRADE_, EXER_GRADE_), target_(target) {}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target_;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw(std::exception)
{
	if (!this->isSigned())
	{
		throw(Form::GradeNotSignedException());
	}
	if (this->getExecGrade() > executor.getGrade())
	{
		throw(Form::GradeTooLowException(executor.getGrade(), this->getExecGrade()));
	}
	srand(time(NULL));
	std::cout << "$%&%@#$&@*^$%@&#$^$#^%#$@%$#^%@$*^*%$@&$#@$#" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->target_ << " has been robotomized successfully." << std::endl;
	else
		std::cerr << this->target_ << " has been robotomized failed." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& in)
{
		return os << in.getName() 
		<< ", Target " << in.getTarget()
		<< ", sign grade " << in.getSignGrade() 
		<< ", execute grade " << in.getExecGrade();
}
