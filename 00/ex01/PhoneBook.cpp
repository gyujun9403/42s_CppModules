#include "PhoneBook.hpp"

void PhoneBook::addPage()
{
	static int idx = 0;

	this->page_[idx].setContact();
	idx = (idx + 1) % 8;
}

void PhoneBook::searchPage()
{
	for (int i = 0; i < 8; i++)
	{
		this->page_[i].prtContactSimple(i + 1);
	}
}

void PhoneBook::searchPage(int idx)
{
	this->page_[idx - 1].prtContact();
}