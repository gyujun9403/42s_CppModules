#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: Form(other.getName(), other.getSignGrade(), other.getExecGrade()), target_(other.target_) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	const_cast<std::string&>(this->target_) = other.target_;
	static_cast<Form&>(*this) = other;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", SIGN_GRADE_, EXER_GRADE_), target_(target) {}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target_;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const throw(std::exception)
{
	if (this->isSigned() && this->getExecGrade() <= executor.getGrade())
	{
		std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
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

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& in)
{
		return os << in.getName() 
		<< ", Target " << in.getTarget()
		<< ", sign grade " << in.getSignGrade() 
		<< ", execute grade " << in.getExecGrade();	
}
