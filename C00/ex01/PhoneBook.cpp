//
// Created by 연규준 on 2022/03/08.
//

#include "PhoneBook.hpp"

void PhoneBook::addPage()
{
	static int idx = 0;

	this->page[idx].setPage();
	idx = (idx + 1) % 8;
}

void PhoneBook::searchPage()
{
	for (int i = 0; i < 8; i++)
		this->page[i].prtPageSimple();
}

void PhoneBook::searchPage(int idx)
{
	this->page[idx - 1].prtPage();
}