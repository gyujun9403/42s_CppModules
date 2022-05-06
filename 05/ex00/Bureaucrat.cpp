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

Bureaucrat::Bureaucrat(std::string name, int grade) throw(std::exception)
: name_(name)
{
	if (grade > MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(MAX_GRADE);
	else if (grade < MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(MIN_GRADE);
	this->grade_ = grade;
}

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

Bureaucrat::~Bureaucrat()
{
	;
}