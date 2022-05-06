#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
	// ****************[canonical class form]****************
protected:
	// 🌟
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

	// 🌟extent of std::exception's exceptions
	class GradeTooHighException: public std::exception
	{
	private:
		// exception message
		std::string message_;
	public:
		virtual ~GradeTooHighException() throw() {return ;}
		// 🌟 constructor
		GradeTooHighException(int max);
		GradeTooHighException(int max, int now);
		// 🌟 class that extent std::exception must override 
		//		'virtual const char* what() const throw()'.
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	private:
		std::string message_;
	public:
		// error: exception specification of overriding function is more lax than base version
		virtual ~GradeTooLowException() throw() {return ;}
		GradeTooLowException(int min);
		GradeTooLowException(int min, int now);
		virtual const char* what() const throw();
	};

public:
	Bureaucrat(std::string name, int grade) throw(std::exception);
	std::string getName() const;
	int getGrade() const;
	// 🌟 this func will generate std::exception object, and throw it 'catch() {...}' as execption.
	// 		if it will throw anything, throw(...).
	// 		and if it won't throw execption, throw().
	void incrementGrade(int up) throw(std::exception);
	void decrementGrade(int down) throw(std::exception);
};


#endif