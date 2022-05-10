#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	;
}

// Super class constructor explicit call
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: Form(other.getName(), other.getSignGrade(), other.getExecGrade()), target_(other.target_)
{
	;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	const_cast<std::string&>(this->target_) = other.target_;
	static_cast<Form&>(*this) = other;
	// this->set = other.signed_;
	// const_cast<int &>(this->signGrade_) = other.signGrade_;
	// const_cast<int &>(this->execGrade_) = other.execGrade_;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 145, 137), target_(target)
{
	;
}

/*
헤더랑 정의에 const 없으면 this->getTarget();시 아래같은 애러 발생.
	const ShrubberyCreationForm *this
	the object has type qualifiers that are not compatible with the member function "ShrubberyCreationForm::getTarget"C/C++(1086)
	ShrubberyCreationForm.cpp(43, 3): object type is: const ShrubberyCreationForm
*/
std::string ShrubberyCreationForm::getTarget() const
{
	return this->target_;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const throw(std::exception)
{
	// sign여부 확인
	if (this->isSigned() && this->getExecGrade() > executor.getGrade())
	{
		std::ofstream ofs(this->getTarget().append("_shrubbery").c_str());
		ofs << "  *  " << std::endl
			<< " *** " << std::endl
			<< "*****" << std::endl
			<< "  |  " << std::endl
			<< "----- gyeon" << std::endl;
		ofs.close();
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

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& in)
{
		return os << in.getName() 
		<< ", Target " << in.getTarget()
		<< ", sign grade " << in.getSignGrade() 
		<< ", execute grade " << in.getExecGrade() <<std::endl;
		
}