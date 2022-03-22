#ifndef C00_PHONEBOOK_H
#define C00_PHONEBOOK_H

#include "Page.hpp"

class PhoneBook {
private:
	Page page[8];
public:
	void addPage();
	void searchPage();
	void searchPage(int idx);
};


#endif
