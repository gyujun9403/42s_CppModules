#include "Brain.hpp"
#include <iostream>

Brain::Brain(){	;}

Brain::~Brain(){ ;}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < SIZEOFIDEAS; i++)
	{
		if (!other.ideas_[i].empty())
			this->ideas_[i].assign(other.ideas_[i]);
		else
			this->ideas_[i].clear();
	}
}

Brain& Brain::operator=(const Brain& other)
{
	for (int i = 0; i < SIZEOFIDEAS; i++)
	{
		if (!other.ideas_[i].empty())
			this->ideas_[i].assign(other.ideas_[i]);
		else
			this->ideas_[i].clear();
	}
	return *this;
}

std::string& Brain::getIdea(int idx)
{
	if (idx >= SIZEOFIDEAS)
	{
		std::cerr << "Parameter of getIdea() is bigger then Ideas size(" << SIZEOFIDEAS << ").\n You get last one." << std::endl;
		return this->ideas_[SIZEOFIDEAS - 1];
	}
	return this->ideas_[idx];
}
