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
	if (this == &other)
		return *this;
	const_cast<std::string&>(this->target_) = other.target_;
	static_cast<Form&>(*this) = other;
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
	if (this->isSigned() && this->getExecGrade() <= executor.getGrade())
	{
		// TODO:
		srand(time(NULL));
		std::cout << "$%&%@#$&@*^$%@&#$^$#^%#$@%$#^%@$*^*%$@&$#@$#" << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->target_ << " has been robotomized successfully." << std::endl;
		else
			std::cerr << this->target_ << " has been robotomized failed." << std::endl;
	}
	else if(!this->isSigned())
	{
		throw(Form::GradeNotSignedException());
	}
	else
	{
		throw(Form::GradeTooLowException(executor.getGrade(), this->getExecGrade()));
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& in)
{
		return os << in.getName() 
		<< ", Target " << in.getTarget()
		<< ", sign grade " << in.getSignGrade() 
		<< ", execute grade " << in.getExecGrade();
}
