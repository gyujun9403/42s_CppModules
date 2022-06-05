#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	// ****************[canonical class form]****************
private:
	Form(); // default constructor
	Form& operator=(const Form& other); // (copy) assignment operator
public:
	virtual ~Form(); // destructor
	Form(const Form& other); // copy constructor
	// ******************************************************

protected:
	class GradeTooHighException: public std::exception
	{
	private:
		std::string message_;
	public:
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(int max);
		GradeTooHighException(int max, int now);
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	private:
		std::string message_;
	public:
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(int min);
		GradeTooLowException(int min, int now);
		virtual const char* what() const throw();
	};
	class GradeNotSignedException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
private:
	const static int LOWEST_GRADE = 150;
	const static int HIGHEST_GRADE = 1;
	const std::string name_;
	const int signGrade_;
	const int execGrade_;
	bool signed_;
public:
	Form(std::string name, int signGrade, int execGrade) throw(std::exception);
	std::string getName() const;
	int getExecGrade() const;
	int getSignGrade() const;
	bool isSigned() const;
	bool beSigned(const Bureaucrat& bc) throw(std::exception);
	// 🌟
	virtual void execute(Bureaucrat const & executor) const throw(std::exception) = 0;
};
std::ostream& operator<<(std::ostream& os, const Form& in);

#endif