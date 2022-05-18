#ifndef C00_PHONEBOOK_H
#define C00_PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
private:
	Contact page_[8];
public:
	void addPage();
	void searchPage();
	void searchPage(int idx);
};


#endif
