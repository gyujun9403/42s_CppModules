//
// Created by 연규준 on 2022/03/08.
//

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


#endif //C00_PHONEBOOK_H
