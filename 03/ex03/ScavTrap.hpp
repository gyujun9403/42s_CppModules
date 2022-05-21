#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// 🌟ClapTrapd을 가상 상속하여, 이후에 FragTrap을 상속받을 클래스에서 발생할 중복 상속 문제 해결.
//class ScavTrap : virtual public ClapTrap
class ScavTrap : virtual public ClapTrap
{
	// ****************[canonical class form]****************
protected:
	ScavTrap();								// default constructor
public:
	virtual ~ScavTrap();							// destructor
	ScavTrap(const ScavTrap& other);			// copy constructor
	ScavTrap& operator=(const ScavTrap& other);	// (copy) assignment operator
	// ******************************************************

protected:
	const static int INITIAL_HIT_POINT = 100;
	const static int INITIAL_ENERGY_POINT = 50;
	const static int INITIAL_ATTACK_DAMAGE = 20;

public:
	ScavTrap(const std::string name);
	void attack(std::string const & target);
	void guardGate();
	virtual int getInitHP() const;
};

#endif