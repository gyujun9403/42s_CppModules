//
// Created by 연규준 on 2022/03/08.
//

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string input;

	while (1) {
		std::cout << "command> ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			pb.addPage();
		else if (input == "SEARCH") {
			std::cout << "index> ";
			std::getline(std::cin, input);
			if (input.size() == 1 && input.find_first_of("12345678") != std::string::npos)
				pb.searchPage(input[0] - 48);
			else if (input == "")
				pb.searchPage();
			else
				std::cout << "Wrong index." << std::endl;
		}
		else
			std::cout << "Wrong command." << std::endl;
	}
	return 0;
}