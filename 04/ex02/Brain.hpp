#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	const static int SIZEOFIDEAS = 6;
	std::string ideas_[SIZEOFIDEAS];

	// ****************[canonical class form]****************
public:
	Brain(); // default constructor
	 ~Brain(); // destructor
	Brain(const Brain& other); // copy constructor
	Brain& operator=(const Brain& other); // (copy) assignment operator
	// ******************************************************
	std::string& getIdea(int idx);
};

#endif
