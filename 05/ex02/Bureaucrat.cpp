#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

int Bureaucrat::MIN_GRADE = 1;
int Bureaucrat::MAX_GRADE = 150;

Bureaucrat::GradeTooHighException::GradeTooHighException(int max)
{
	std::stringstream tempStr;

	tempStr << "Maximum Grade is " << max << ".";
	this->message_ = tempStr.str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int max, int now)
{ 
	std::stringstream tempStr;

	tempStr << "Maximum Grade is " << max << ", and now grade is " << now << ".";
	this->message_ = tempStr.str();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->message_.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int min)
{
	std::stringstream tempStr;

	tempStr << "Minimum Grade is " << min << ".";
	this->message_ = tempStr.str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int min, int now)
{
	std::stringstream tempStr;

	tempStr << "Minimum Grade is " << min << ", and now grade is " << now << ".";
	this->message_ = tempStr.str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->message_.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::Bureaucrat(std::string name): name_(name){}

void Bureaucrat::incrementGrade(int up) throw(std::exception)
{
	int tempGrade;

	tempGrade = this->grade_ + up;
	if (tempGrade > MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(MAX_GRADE, this->grade_);
	this->grade_ = tempGrade;
}

void Bureaucrat::decrementGrade(int down) throw(std::exception)
{
	int tempGrade;

	tempGrade = this->grade_ - down;
	if (tempGrade < MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(MIN_GRADE, this->grade_);
	this->grade_ = tempGrade;
}

std::string Bureaucrat::getName() const
{
	return this->name_;
}

int Bureaucrat::getGrade() const
{
	return this->grade_;
}

void Bureaucrat::setGrade(const int grade) throw(std::exception)
{
	
	// 🌟throw std::exception object.
	if (grade > MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(MAX_GRADE);
	else if (grade < MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(MIN_GRADE);
	// 🌟if exception was thrown, this code don't be run.
	this->grade_ = grade;
}

bool Bureaucrat::signForm(const Form& form)
{
	if (form.getSignGrade() >= this->grade_)
	{
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cerr << this->getName() << " couldn’t sign " << form.getName() << " because ";
		throw GradeTooLowException(this->grade_, form.getSignGrade());
	}
}

bool Bureaucrat::executeForm(Form const & form)
{
	if (form.getExecGrade() >= this->grade_)
	{
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cerr << this->getName() << " couldn’t execute " << form.getName() << " because ";
		throw GradeTooLowException(this->grade_, form.getExecGrade());
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& in)
{
	return os << in.getName() << ", bureaucrat grade " << in.getGrade() << ".";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name_(other.name_)
{
	this->grade_ = other.grade_;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade_ = other.grade_;
	return *this;
}

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
