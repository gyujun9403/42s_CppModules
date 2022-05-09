#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat gyeon("gyeon", 120);
	Form form1("form1", 80, 60);
	Form form2 = form1;
	Form form3("form3", 130, 122);
	try
	{
		Form form4("form4", 80, 190);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----[prt forms info]-----" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;

	std::cout << "-------[sign form1]-------" << std::endl;
	try
	{
		gyeon.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-------[sign form2]-------" << std::endl;
	try
	{
		gyeon.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--[copy form3 to form 1]--" << std::endl;
	form1 = form3;
	std::cout << form1 <<std::endl;
	std::cout << "form1 signed? :" << form1.isSigned() << std::endl;
	try
	{
		gyeon.signForm(form1);
		form1.beSigned(gyeon);
		std::cout << "form1 signed? :" << form1.isSigned() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 1;
}