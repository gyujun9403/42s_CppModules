#include "TypeFinder.hpp"
#include <iostream>

TypeFinder::TypeFinder() { ;}

TypeFinder::~TypeFinder() { ;}

TypeFinder::TypeFinder(const TypeFinder& other)
{
	static_cast<void>(other);
}

TypeFinder& TypeFinder::operator=(const TypeFinder& other)
{
	static_cast<void>(other);
	return *this;
}

Base* TypeFinder::generate(void)
{
	int randomThree;

	srand(time(NULL) % rand());
	randomThree = rand() % 3;
	if (randomThree == 0)
	{
		std::cout << "Generated A" << std::endl;
		return new A();
	}
	else if (randomThree == 1)
	{
		std::cout << "Generated B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return new C();
	}
}

void TypeFinder::identify(Base* p)
{	
	// 🌟if ptr p is now class A, dynamic_cast return null
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "\e[32m" << "identify_ptr :A" << "\e[0m" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "\e[32m" << "identify_ptr :B" << "\e[0m" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "\e[32m" << "identify_ptr :C" << "\e[0m" << std::endl;
	else
		std::cout << "\e[31m" << "identify_ptr :Unknown type class." << "\e[0m" << std::endl;
}

void TypeFinder::identify(Base& p)
{
	Base unusedBase;
	static int i = 0;
	try
	{
		if (i == 0)
		{
			// 🌟if ref p is now class A, dynamic_cast throw std::bad_cast exception
			unusedBase = dynamic_cast<A&>(p);
			std::cout << "\e[32m" << "identify_ref :A" << "\e[0m" << std::endl;
		}
		else if (i == 1)
		{
			unusedBase = dynamic_cast<B&>(p);
			std::cout << "\e[32m" << "identify_ref :B" << "\e[0m" << std::endl;
		}
		else if (i == 2)
		{
			unusedBase = dynamic_cast<C&>(p);
			std::cout << "\e[32m" << "identify_ref :C" << "\e[0m" << std::endl;
		}
		else
			std::cout  << "\e[31m"<< "identify_ref :Unknown type class." << "\e[0m" << std::endl;
	}
	catch(std::exception& e)
	{
		++i;
		identify(p);
	}
	i = 0;
}
