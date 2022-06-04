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

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::Bureaucrat(std::string name): name_(name){}

void Bureaucrat::upGrade(int up) throw(std::exception)
{
	int tempGrade;

	tempGrade = this->grade_ - up;
	// 🌟throw std::exception object.
	if (tempGrade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException(HIGHEST_GRADE, this->grade_);
	// 🌟if exception was thrown, this code don't be run.
	this->grade_ = tempGrade;
}

void Bureaucrat::downGrade(int down) throw(std::exception)
{
	int tempGrade;

	tempGrade = this->grade_ + down;
	if (tempGrade > LOWSET_GRADE)
		throw Bureaucrat::GradeTooLowException(LOWSET_GRADE, this->grade_);
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
		throw Bureaucrat::GradeTooHighException(HIGHEST_GRADE);
	else if (grade > LOWSET_GRADE)
		throw Bureaucrat::GradeTooLowException(LOWSET_GRADE);
	this->grade_ = grade;
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

// copy and swap ->  원본값 보장.
// TODO: 아에 막아버리게 필요한경우만 막게...
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	this->grade_ = other.grade_;
	return *this;
}

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
