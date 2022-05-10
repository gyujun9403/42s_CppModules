#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

// Super class constructor explicit call
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: Form(other.getName(), other.getSignGrade(), other.getExecGrade()), target_(other.target_)
{
	;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	const_cast<std::string&>(this->target_) = other.target_;
	static_cast<Form&>(*this) = other;
	// this->set = other.signed_;
	// const_cast<int &>(this->signGrade_) = other.signGrade_;
	// const_cast<int &>(this->execGrade_) = other.execGrade_;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45), target_(target)
{
	;
}

/*
헤더랑 정의에 const 없으면 this->getTarget();시 아래같은 애러 발생.
	const RobotomyRequestForm *this
	the object has type qualifiers that are not compatible with the member function "RobotomyRequestForm::getTarget"C/C++(1086)
	RobotomyRequestForm.cpp(43, 3): object type is: const RobotomyRequestForm
*/
std::string RobotomyRequestForm::getTarget() const
{
	return this->target_;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw(std::exception)
{
	// sign여부 확인
	if (this->isSigned() && this->getExecGrade() > executor.getGrade())
	{
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
	// grade가 실행하기 충분이 큰지 확인
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& in)
{
		return os << in.getName() 
		<< ", Target " << in.getTarget()
		<< ", sign grade " << in.getSignGrade() 
		<< ", execute grade " << in.getExecGrade() <<std::endl;
		
}