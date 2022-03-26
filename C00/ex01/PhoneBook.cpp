#include "PhoneBook.hpp"

void PhoneBook::addPage()
{
	static int idx = 0;

	this->page[idx].setContact();
	idx = (idx + 1) % 8;
}

void PhoneBook::searchPage()
{
	for (int i = 0; i < 8; i++)
		this->page[i].prtContactSimple(i + 1);
}

void PhoneBook::searchPage(int idx)
{
	this->page[idx - 1].prtContact();
}