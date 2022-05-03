#ifndef FARGTRAP_HPP
# define FARGTRAP_HPP

#include "ClapTrap.hpp"

// 🌟ClapTrapd을 가상 상속하여, 이후에 FragTrap을 상속받을 클래스에서 발생할 중복 상속 문제 해결.
class FragTrap : virtual public ClapTrap
{
	// ****************[canonical class form]****************
private:
	FragTrap();								// default constructor
public:
	~FragTrap();							// destructor
	FragTrap(const ClapTrap& other);			// copy constructor
	FragTrap& operator=(const FragTrap& other);	// (copy) assignment operator
	// ******************************************************

protected:
	const static int INITIAL_HIT_POINT = 100;
	const static int INITIAL_ENERGY_POINT = 100;
	const static int INITIAL_ATTACK_DAMAGET = 30;

public:
	FragTrap(const std::string name);
	void FragTrap::attack(std::string const & target);
	void highFivesGuys(void);
};

#endif