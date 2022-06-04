#include <iostream>
#include <sstream>
#include "Form.hpp"

int Form::MIN_GRADE = 1;
int Form::MAX_GRADE = 150;

Form::GradeTooHighException::GradeTooHighException(int max)
{
	std::stringstream tempStr;

	tempStr << "Maximum Grade is " << max << ".";
	this->message_ = tempStr.str();
}

Form::GradeTooHighException::GradeTooHighException(int max, int now)
{
	std::stringstream tempStr;

	tempStr << "Maximum Grade is " << max << ", and now grade is " << now << ".";
	this->message_ = tempStr.str();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return this->message_.c_str();
}

Form::GradeTooLowException::GradeTooLowException(int min)
{
	std::stringstream tempStr;

	tempStr << "Minimum Grade is " << min << ".";
	this->message_ = tempStr.str();
}

Form::GradeTooLowException::GradeTooLowException(int min, int now)
{
	std::stringstream tempStr;

	tempStr << "Up than " << min << ", and now grade is " << now << ".";
	this->message_ = tempStr.str();
}

const char* Form::GradeTooLowException::what() const throw()
{
	return this->message_.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {return ;}
Form::GradeTooLowException::~GradeTooLowException() throw() {return ;}

Form::Form(std::string name, int signGrade, int execGrade) throw(std::exception)
: name_(name), signGrade_(signGrade), execGrade_(execGrade), signed_(false)
{
	if (this->signGrade_ < MIN_GRADE | this->execGrade_ < MIN_GRADE)
		throw GradeTooLowException(MIN_GRADE);
	else if (this->signGrade_ > MAX_GRADE | this->execGrade_ > MAX_GRADE)
		throw GradeTooHighException(MAX_GRADE);
}

std::string Form::getName() const
{
	return this->name_;
}

int Form::getSignGrade() const
{
	return this->signGrade_;
}

int Form::getExecGrade() const
{
	return this->execGrade_;
}

bool Form::isSigned() const
{
	return this->signed_;
}

bool Form::beSigned(const Bureaucrat& bc) throw(std::exception)
{
	if (this->signGrade_ <= bc.getGrade())
	{
		this->signed_ = true;
		return true;
	}
	else
	{
		this->signed_ = false;
		throw (GradeTooLowException(bc.getGrade(), this->signGrade_));
	}
}

std::ostream& operator<<(std::ostream& os, const Form& in)
{
	return os << in.getName() << ", sign grade " 
		<< in.getSignGrade() << ", execute grade " 
		<< in.getExecGrade();
}

Form::Form(const Form& other)
: name_(other.name_), signGrade_(other.signGrade_), execGrade_(other.execGrade_), signed_(other.signed_) {}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	this->signed_ = other.signed_;
	const_cast<int &>(this->signGrade_) = other.signGrade_;
	const_cast<int &>(this->execGrade_) = other.execGrade_;
	return *this;
}

Form::~Form() {;}
