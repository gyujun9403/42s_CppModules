#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// ๐ClapTrapd์ ๊ฐ์ ์์ํ์ฌ, ์ดํ์ FragTrap์ ์์๋ฐ์ ํด๋์ค์์ ๋ฐ์ํ  ์ค๋ณต ์์ ๋ฌธ์  ํด๊ฒฐ.
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