#ifndef C00_PAGE_H
#define C00_PAGE_H

#include <iostream>
#include <iomanip>

#define ALL_ALPHA	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALL_NUMBER	"0123456789"
#define WHITE_SPACE	"\a\b\f\n\r\t\v "

class Contact {
private:
	std::string	first_name_;
	std::string	last_name_;
	std::string	nickname_;
	std::string	phone_number_;
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
	void setContact();
	void prtContact();
	void prtContactSimple(int idx);
};


#endif
