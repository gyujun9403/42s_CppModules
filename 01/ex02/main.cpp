//
// Created by 연규준 on 2022/03/26.
//
#include <iostream>

int main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << &str << " :" << str << std::endl;
	std::cout << stringPTR << " :" << str << std::endl;
	std::cout << &stringREF << " :" << str << std::endl;
}