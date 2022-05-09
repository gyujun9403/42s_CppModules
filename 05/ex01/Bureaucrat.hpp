#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include "Form.hpp"

// 🌟 error unknown type name 'Form' occur when you don't make beSigned(...) in cpp
class Form;

class Bureaucrat
{
	// ****************[canonical class form]****************
protected:
	Bureaucrat();									// default constructor
public:
	virtual ~Bureaucrat();							// destructor
	Bureaucrat(const Bureaucrat& other);			// copy constructor
	Bureaucrat& operator=(const Bureaucrat& other);	// (copy) assignment operator
	// ******************************************************

private:
	static int MIN_GRADE;
	static int MAX_GRADE;
	const std::string name_;
	int grade_;

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

public:
	Bureaucrat(std::string name, int grade) throw(std::exception);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int up) throw(std::exception);
	void decrementGrade(int down) throw(std::exception);
	void signForm(const Form& form);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& in);

#endif