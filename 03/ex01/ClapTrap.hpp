#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	// ****************[canonical class form]****************
protected:
	ClapTrap();								// default constructor
public:
	~ClapTrap();							// destructor
	ClapTrap(const ClapTrap& other);			// copy constructor
	ClapTrap& operator=(const ClapTrap& other);	// (copy) assignment operator
	// ******************************************************

protected:
	const static int INITIAL_HIT_POINT = 10;
	const static int INITIAL_ENERGY_POINT = 10;
	const static int INITIAL_ATTACK_DAMAGET = 0;

	std::string name_;
	int	hitPoint_;
	int energyPoint_;
	int attackDamage_;
public:
	ClapTrap(const std::string name);
	void attack(std::string const & target);	// attack target to lose <attackDamage_>, cost 1 <energyPoint_>.
	void takeDamage(unsigned int amount);		// take damage <amount>. so, lose <hitPoint_>.
	void beRepaired(unsigned int amount);		// repair <hitPoint_> <amount>, cost 1 energy point.
	std::string getName();
	int getHitPoint() const;
	int getEnergyPoint() const;
	int getAttackDamage() const;
	void setAttackDamage(const unsigned int attackDamage);
};

#endif