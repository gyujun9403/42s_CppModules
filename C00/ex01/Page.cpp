#include "Page.hpp"

void Page::setFirstName()
{
	std::string input;
	while (1) {
		std::cout << "Write your first name> ";
		std::getline(std::cin, input);
		if (input.find_first_not_of(ALL_ALPHA) == std::string::npos) {
			first_name_.assign(input);
			break;
		}
		else
			std::cout << "Write only alphabet without spaces." << std::endl;
	}
}

void Page::setLastName()
{
	std::string input;
	while (1) {
		std::cout << "Write your last name> ";
		std::getline(std::cin, input);
		if (input.find_first_not_of(ALL_ALPHA) == std::string::npos) {
			last_name_.assign(input);
			break;
		}
		else
			std::cout << "Write only alphabet without spaces." << std::endl;
	}
}

void Page::setNickname()
{
	std::string input;
	while (1) {
		std::cout << "Write your nickname> ";
		std::getline(std::cin, input);
		if (input.find(WHITE_SPACE) == std::string::npos) {
			nickname_.assign(input);
			break;
		}
		else
			std::cout << "Write without white spaces." << std::endl;
	}
}

void Page::setPhoneNumber()
{
	std::string input;
	while (1) {
		std::cout << "Write your phone number without '-'> ";
		std::getline(std::cin, input);
		if (input.find_first_not_of("0123456789") == std::string::npos) {
			phone_number_.assign(input);
			break;
		}
		else
			std::cout << "Write only number." << std::endl;
	}
}

void Page::setDarkestSecret()
{
	std::string input;
	std::cout << "Tell me your darkest secret> ";
	std::getline(std::cin, input);
	darkest_secret_.assign(input);
}

void Page::setPage()
{
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
}

void Page::prtPage()
{
	if (first_name_.empty())
		std::cout << "This page is EMPTY!" << std::endl;
	else {
		std::cout << "first name	: " << first_name_ << std::endl;
		std::cout << "last name	: " << last_name_ << std::endl;
		std::cout << "nickname	: " << nickname_ << std::endl;
		std::cout << "phone number	: " << phone_number_ << std::endl;
	}
}

std::string Page::adjustFirstNameSimple()
{
	std::string result_str;
	std::cout << std::setw(10);
	if (first_name_.size() > 10) {
		result_str.assign(first_name_, 0, 9);
		result_str.append(".");
	}
	else
		result_str.assign(first_name_);
	return result_str;
}
std::string Page::adjustLastNameSimple()
{
	std::string result_str;
	std::cout << std::setw(10);
	if (last_name_.size() > 10) {
		result_str.assign(last_name_, 0, 9);
		result_str.append(".");
	}
	else
		result_str.assign(last_name_);
	return result_str;
}

std::string Page::adjustNicknameSimple()
{
	std::string result_str;
	std::cout << std::setw(10);
	if (nickname_.size() > 10) {
		result_str.assign(nickname_, 0, 9);
		result_str.append(".");
	}
	else
		result_str.assign(nickname_);
	return result_str;
}

std::string Page::adjustPhoneNumberSimple()
{
	std::string result_str;
	std::cout << std::setw(10);
	if (phone_number_.size() > 10) {
		result_str.assign(phone_number_, 0, 9);
		result_str.append(".");
	}
	else
		result_str.assign(phone_number_);
	return result_str;
}

void Page::prtPageSimple()
{
	if (!first_name_.empty())
		std::cout << adjustFirstNameSimple() << "|"
			<< adjustLastNameSimple() << "|"
			<< adjustNicknameSimple() << "|"
			<< adjustPhoneNumberSimple() << std::endl;
}