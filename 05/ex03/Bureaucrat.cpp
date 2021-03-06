#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(int max)
{
	std::stringstream tempStr;

	tempStr << "Highest Grade is " << max << ".";
	this->message_ = tempStr.str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int max, int now)
{ 
	std::stringstream tempStr;

	tempStr << "Highest Grade is " << max << ", and now grade is " << now << ".";
	this->message_ = tempStr.str();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->message_.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int min)
{
	std::stringstream tempStr;

	tempStr << "Lowest Grade is " << min << ".";
	this->message_ = tempStr.str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int min, int now)
{
	std::stringstream tempStr;

	tempStr << "Lowest Grade is " << min << ", and now grade is " << now << ".";
	this->message_ = tempStr.str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->message_.c_str();
}

const char* Bureaucrat::GradeNotSignedException::what() const throw()
{
	return "This form is not signed!";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::Bureaucrat(std::string name): name_(name){}

void Bureaucrat::upGrade(int up) throw(std::exception)
{
	int tempGrade;

	tempGrade = this->grade_ - up;
	if (tempGrade < HIGHEST_GRADE)
	{
		throw Bureaucrat::GradeTooHighException(HIGHEST_GRADE, this->grade_);
	}
	this->grade_ = tempGrade;
}

void Bureaucrat::downGrade(int down) throw(std::exception)
{
	int tempGrade;

	tempGrade = this->grade_ + down;
	if (tempGrade > LOWSET_GRADE)
	{
		throw Bureaucrat::GradeTooLowException(LOWSET_GRADE, this->grade_);
	}
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
	
	if (grade < HIGHEST_GRADE)
	{
		throw Bureaucrat::GradeTooHighException(HIGHEST_GRADE);
	}
	if (grade > LOWSET_GRADE)
	{
		throw Bureaucrat::GradeTooLowException(LOWSET_GRADE);
	}
	this->grade_ = grade;
}

bool Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << this->getName() << " couldn???t sign " << form.getName() << " because ";
		std::cerr << e.what() << "\e[0m" << std::endl;
		return false;
	}
	std::cout << "\e[32m" << this->getName() << " signed " << form.getName() << "\e[0m" << std::endl;
	return true;
}

bool Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(std::exception& e)
	{
		std::cerr << "\e[31m" << this->getName() << " couldn???t execute " << form.getName() << " because ";
		std::cerr << e.what() << "\e[0m" << std::endl;
		return false;
	}
	std::cout << "\e[32m" << this->getName() << " executed " << form.getName() << "\e[0m" << std::endl;
	return true;
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
