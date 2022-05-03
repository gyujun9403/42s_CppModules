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
	~DiamondTrap();									// destructor
	DiamondTrap(const DiamondTrap& other);			// copy constructor
	DiamondTrap& operator=(const DiamondTrap& other);	// (copy) assignment operator
	// ******************************************************	

private:
	std::string name_;
public:
	DiamondTrap(std::string name);
	// 이미있는걸 한번 더 선언 한 것. 사용할때 ::을 통해서 한정지어야 한다.
	// ScavTrap::attack(std::string const & target);
	// 🌟 주석처리 해서 multiple base classes of different types에러 띄우기
	void attack(std::string const & target);
	std::string getName() const;
	void whoAmI();
};

#endif