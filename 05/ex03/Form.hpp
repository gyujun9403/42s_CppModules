#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

// 🌟 error unknown type name 'Bureaucrat' occur when you don't make beSigned(...) in cpp
class Bureaucrat;

class Form
{
	// ****************[canonical class form]****************
private:
	Form();								// default constructor
public:
	virtual ~Form();					// destructor
	Form(const Form& other);			// copy constructor
	Form& operator=(const Form& other);	// (copy) assignment operator
	// ******************************************************

private:
	static int MIN_GRADE;
	static int MAX_GRADE;
	const std::string name_;
	const int signGrade_;
	const int execGrade_;
	bool signed_;

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
	// private:
	// 	std::string message_;
	public:
		//virtual ~GradeNotSignedException() throw();
		virtual const char* what() const throw();
	};

public:
	Form(std::string name, int signGrade, int execGrade) throw(std::exception);
	std::string getName() const;
	int getExecGrade() const;
	int getSignGrade() const;
	bool isSigned() const;
	bool beSigned(const Bureaucrat& bc) throw(std::exception);
	// 🌟abstract class
	virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Form& in);

#endif