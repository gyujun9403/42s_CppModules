#ifndef FARGTRAP_HPP
# define FARGTRAP_HPP

#include "ClapTrap.hpp"

// ๐ClapTrapd์ ๊ฐ์ ์์ํ์ฌ, ์ดํ์ FragTrap์ ์์๋ฐ์ ํด๋์ค์์ ๋ฐ์ํ  ์ค๋ณต ์์ ๋ฌธ์  ํด๊ฒฐ.
//class FragTrap : virtual public ClapTrap
class FragTrap : virtual public ClapTrap
{
	// ****************[canonical class form]****************
protected:
	FragTrap();								// default constructor
public:
	virtual ~FragTrap();						// destructor
	FragTrap(const FragTrap& other);			// copy constructor
	FragTrap& operator=(const FragTrap& other);	// (copy) assignment operator
	// ******************************************************

protected:
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