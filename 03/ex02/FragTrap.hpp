#ifndef FARGTRAP_HPP
# define FARGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	// ****************[canonical class form]****************
private:
	FragTrap();								// default constructor
public:
	virtual ~FragTrap();							// destructor
	FragTrap(const FragTrap& other);			// copy constructor
	FragTrap& operator=(const FragTrap& other);	// (copy) assignment operator
	// ******************************************************

private:
	const static int INITIAL_HIT_POINT = 100;
	const static int INITIAL_ENERGY_POINT = 100;
	const static int INITIAL_ATTACK_DAMAGE = 30;

public:
	FragTrap(const std::string name);
	void attack(std::string const & target);
	void highFivesGuys(void);
	virtual int getInitHP() const;
};

#endif