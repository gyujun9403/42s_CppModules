#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: Form(other.getName(), other.getSignGrade(), other.getExecGrade()), target_(other.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	const_cast<std::string&>(this->target_) = other.target_;
	static_cast<Form&>(*this) = other;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", SIGN_GRADE_, EXER_GRADE_), target_(target) {}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target_;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const throw(std::exception)
{
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
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& in)
{
		return os << in.getName() 
		<< ", Target " << in.getTarget()
		<< ", sign grade " << in.getSignGrade() 
		<< ", execute grade " << in.getExecGrade() <<std::endl;
}
