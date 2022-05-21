#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// 다중상속
class DiamondTrap : public ScavTrap, public FragTrap
{
	// ****************[canonical class form]****************
private:
	DiamondTrap();									// default constructor
public:
	virtual ~DiamondTrap();									// destructor
	DiamondTrap(const DiamondTrap& other);			// copy constructor
	DiamondTrap& operator=(const DiamondTrap& other);	// (copy) assignment operator
	// ******************************************************	

private:
	std::string name_;
public:
	DiamondTrap(std::string name);
	// ⬇️this defines ScavTrap::attack twice in ScavTrapn and here.
	//void ScavTrap::attack(std::string const & target);
	// ⬇️[❌error] multiple base classes of different types
	void attack(std::string const & target);
	std::string getName() const;
	void whoAmI();
	virtual int getInitHP() const;
};

#endif