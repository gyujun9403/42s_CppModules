#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string input;

	while (!std::cin.eof()) {
		std::cout << "command> ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			pb.addPage();
		else if (input == "SEARCH") {
			while (!std::cin.eof()) {
				pb.searchPage();
				std::cout << "index> ";
				std::getline(std::cin, input);
				if (input.size() == 1 && input.find_first_of("12345678") != std::string::npos) {
					pb.searchPage(input[0] - 48);
					break ;
				}
				else if (!std::cin.eof())
					std::cout << "Wrong index. Write an integer between 0 and 8." << std::endl;
			}
		}
		else if (!std::cin.eof())
			std::cout << "Wrong command." << std::endl;
	}
	return 0;
}