#ifndef C00_PAGE_H
#define C00_PAGE_H

#include <iostream>
#include <iomanip>

#define ALL_ALPHA	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALL_NUMBER	"0123456789"
#define WHITE_SPACE	"\a\b\f\n\r\t\v "

class Contact {
private:
	std::string	firstName_;
	std::string	lastName_;
	std::string	nickname_;
	std::string	phoneNumber_;
	std::string darkestSecret_;
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
