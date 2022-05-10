#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

// Super class constructor explicit call
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: Form(other.getName(), other.getSignGrade(), other.getExecGrade()), target_(other.target_)
{
	;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	const_cast<std::string&>(this->target_) = other.target_;
	static_cast<Form&>(*this) = other;
	// this->set = other.signed_;
	// const_cast<int &>(this->signGrade_) = other.signGrade_;
	// const_cast<int &>(this->execGrade_) = other.execGrade_;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", 25, 5), target_(target)
{
	;
}

/*
헤더랑 정의에 const 없으면 this->getTarget();시 아래같은 애러 발생.
	const PresidentialPardonForm *this
	the object has type qualifiers that are not compatible with the member function "PresidentialPardonForm::getTarget"C/C++(1086)
	PresidentialPardonForm.cpp(43, 3): object type is: const PresidentialPardonForm
*/
std::string PresidentialPardonForm::getTarget() const
{
	return this->target_;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const throw(std::exception)
{
	// sign여부 확인
	if (this->isSigned() && this->getExecGrade() > executor.getGrade())
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
	// grade가 실행하기 충분이 큰지 확인
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& in)
{
		return os << in.getName() 
		<< ", Target " << in.getTarget()
		<< ", sign grade " << in.getSignGrade() 
		<< ", execute grade " << in.getExecGrade() <<std::endl;
		
}