#ifndef C00_PAGE_H
#define C00_PAGE_H

#include <iostream>
#include <iomanip>

#define ALL_ALPHA	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define WHITE_SPACE	"\a\b\f\n\r\t\v "

class Page {
private:
	std::string darkest_secret_;
	void setFirstName();
	void setLastName();
	void setNickname();
	void setPhoneNumber();
	void setDarkestSecret();
	std::string adjustFirstNameSimple();
	std::string adjustLastNameSimple();
	std::string adjustNicknameSimple();
	std::string adjustPhoneNumberSimple();
public:
	std::string	first_name_;
	std::string	last_name_;
	std::string	nickname_;
	std::string	phone_number_;
	void setPage();
	void prtPage();
	void prtPageSimple();
};


#endif
