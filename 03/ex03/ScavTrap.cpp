#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap() constructor called. " << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "~ScavTrap() destructor called. " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << name_ << " attack " << target << ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
}

// 🌟멤버 이니셜라이저🌟
ScavTrap::ScavTrap(std::string name)
:	ClapTrap::ClapTrap(name)
{
	this->name_ = name;
	this->hitPoint_ = INITIAL_HIT_POINT;
	this->attackDamage_ = INITIAL_ATTACK_DAMAGET;
	this->energyPoint_ = INITIAL_ENERGY_POINT;
	std::cout << "ScavTrap(name) constructor called. " << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->name_ << " enterred Gate keeper mode." << std::endl;
}