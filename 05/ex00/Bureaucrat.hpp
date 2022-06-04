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

	// 🌟extent of std::exception's exceptions
private:
	class GradeTooHighException : public std::exception
	{
	private:
		// exception message
		std::string message_;
	public:
		// error: exception specification of overriding function is more lax than base version
		// -> https://stackoverflow.com/a/18416814's comment(4) 
		virtual ~GradeTooHighException() throw();
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
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(int min);
		GradeTooLowException(int min, int now);
		virtual const char* what() const throw();
	};

private:
	const static int HIGHEST_GRADE = 1;
	const static int LOWSET_GRADE = 150;
	const std::string name_;
	int grade_;

public:
	Bureaucrat(std::string name);
	std::string getName() const;
	int getGrade() const;
	void setGrade(const int grade) throw(std::exception);
	// 🌟 throw(std::exception) generates std::exception object, and throw it 'catch() {...}' as execption.
	// if it will throw anything, throw(...). and if it won't throw execption, throw().
	void upGrade(int up) throw(std::exception);
	void downGrade(int down) throw(std::exception);
};

// a type qualifier is not allowed on a nonmember functionC/C++(1670) ↓
std::ostream& operator<<(std::ostream& os, const Bureaucrat& in);	// const;

#endif
