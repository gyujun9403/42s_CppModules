#include "Contact.hpp"
#include <cstdio>

void Contact::setFirstName()
{
	std::string input;

	std::cin.clear();
	while (1)
	{
		std::cout << "Write your first name> ";
		std::getline(std::cin, input);
		if(!input.empty())
		{
			if (input.find_first_not_of(ALL_ALPHA) == std::string::npos)
			{
				firstName_.assign(input);
				break;
			}
			else
			{
				std::cout << "Write only alphabet without spaces." << std::endl;
			}
		}
	}
}

void Contact::setLastName()
{
	std::string input;

	std::cin.clear();
	while (1)
	{
		std::cout << "Write your last name> ";
		std::getline(std::cin, input);
		if(!input.empty())
		{
			if (input.find_first_not_of(ALL_ALPHA) == std::string::npos)
			{
				lastName_.assign(input);
				break;
			}
			else
			{
				std::cout << "Write only alphabet without spaces." << std::endl;
			}
		}
	}
}

void Contact::setNickname()
{
	std::string input;

	std::cin.clear();
	while (1)
	{
		std::cout << "Write your nickname\n if you don't want, skip this.> ";
		std::getline(std::cin, input);
		if (input.find(WHITE_SPACE) == std::string::npos)
		{
			nickname_.assign(input);
			break;
		}
		else
		{
			std::cout << "Write without white spaces." << std::endl;
		}
	}
}

void Contact::setPhoneNumber()
{
	std::string input;

	std::cin.clear();
	while (1)
	{
		std::cout << "Write your phone number without '-'> ";
		std::getline(std::cin, input);
		if(!input.empty())
		{
			if (input.find_first_not_of(ALL_NUMBER) == std::string::npos)
			{
				phoneNumber_.assign(input);
				break;
			}
			else
			{
				std::cout << "Write only number." << std::endl;
			}
		}
	}
}

void Contact::setDarkestSecret()
{
	std::string input;
	std::cout << "Tell me your darkest secret\n if you don't want, skip this.> ";
	std::getline(std::cin, input);
	darkestSecret_.assign(input);
}

void Contact::setContact()
{
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
}

void Contact::prtContact()
{
	if (firstName_.empty())
	{
		std::cout << "This page is EMPTY!" << std::endl;
	}
	else
	{
		std::cout << "first name	: " << firstName_ << std::endl;
		std::cout << "last name	: " << lastName_ << std::endl;
		std::cout << "nickname	: " << nickname_ << std::endl;
		std::cout << "phone number	: " << phoneNumber_ << std::endl;
	}
}

std::string Contact::adjustFirstNameSimple()
{
	std::string result_str;
	
	std::cout << std::setw(10);
	if (firstName_.size() > 10)
	{
		result_str.assign(firstName_, 0, 9);
		result_str.append(".");
	}
	else
	{
		result_str.assign(firstName_);
	}
	return result_str;
}
std::string Contact::adjustLastNameSimple()
{
	std::string result_str;
	
	std::cout << std::setw(10);
	if (lastName_.size() > 10)
	{
		result_str.assign(lastName_, 0, 9);
		result_str.append(".");
	}
	else
	{
		result_str.assign(lastName_);
	}
	return result_str;
}

std::string Contact::adjustNicknameSimple()
{
	std::string result_str;

	std::cout << std::setw(10);
	if (nickname_.size() > 10)
	{
		result_str.assign(nickname_, 0, 9);
		result_str.append(".");
	}
	else
	{
		result_str.assign(nickname_);
	}
	return result_str;
}

std::string Contact::adjustPhoneNumberSimple()
{
	std::string result_str;
	
	std::cout << std::setw(10);
	if (phoneNumber_.size() > 10)
	{
		result_str.assign(phoneNumber_, 0, 9);
		result_str.append(".");
	}
	else
	{
		result_str.assign(phoneNumber_);
	}
	return result_str;
}

void Contact::prtContactSimple(int idx)
{
	if (!firstName_.empty())
	{
		std::cout.width(10);
		std::cout << idx << "|"
				  << adjustFirstNameSimple() << "|"
				  << adjustLastNameSimple() << "|"
				  << adjustNicknameSimple() << std::endl;
	}
}