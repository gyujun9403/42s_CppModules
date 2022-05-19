#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	// ****************[canonical class form]****************
private:
	ScavTrap();								// default constructor
public:
	~ScavTrap();							// destructor
	ScavTrap(const ScavTrap& other);			// copy constructor
	ScavTrap& operator=(const ScavTrap& other);	// (copy) assignment operator
	// ******************************************************

//protected:
private:
	const static int INITIAL_HIT_POINT = 100;
	const static int INITIAL_ENERGY_POINT = 50;
	const static int INITIAL_ATTACK_DAMAGE = 20;

public:
	ScavTrap(const std::string name);
	void attack(std::string const & target);
	void guardGate();
};

#endif