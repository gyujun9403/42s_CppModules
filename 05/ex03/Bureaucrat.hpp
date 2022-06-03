#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	// ****************[canonical class form]****************
protected:
	Bureaucrat(); // default constructor
public:
	virtual ~Bureaucrat(); // destructor
	Bureaucrat(const Bureaucrat& other); // copy constructor
	Bureaucrat& operator=(const Bureaucrat& other); // (copy) assignment operator
	// ******************************************************

private:
	class GradeTooHighException : public std::exception
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

private:
	static int MIN_GRADE;
	static int MAX_GRADE;
	const std::string name_;
	int grade_;

public:
	Bureaucrat(std::string name);
	std::string getName() const;
	int getGrade() const;
	void setGrade(const int grade) throw(std::exception);
	void incrementGrade(int up) throw(std::exception);
	void decrementGrade(int down) throw(std::exception);
	bool signForm(const Form& form);
	bool executeForm(Form const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& in);

#endif