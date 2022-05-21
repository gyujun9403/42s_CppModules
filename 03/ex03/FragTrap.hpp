#ifndef FARGTRAP_HPP
# define FARGTRAP_HPP

#include "ClapTrap.hpp"

// 🌟ClapTrapd을 가상 상속하여, 이후에 FragTrap을 상속받을 클래스에서 발생할 중복 상속 문제 해결.
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