#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap() constructor called. " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "~DiamondTrap() destructor called. " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name)
{
	DiamondTrap::name_ = name;
	this->hitPoint_ = FragTrap::INITIAL_HIT_POINT;
	this->energyPoint_ = ScavTrap::INITIAL_ENERGY_POINT;
	this->attackDamage_ = FragTrap::INITIAL_ATTACK_DAMAGE;
	std::cout << "DiamondTrap(name) constructor called. " << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

// 🌟 오버라이딩 하지 않으면 밑에서 DiamondTrap::getName()해도 ClapTrap의 getName()이 호출된다.
std::string DiamondTrap::getName() const
{
	return this->name_;
}

void DiamondTrap::whoAmI()
{
	std::cout << "1. ClapTrap's name :" << ClapTrap::getName() << std::endl;
	std::cout << "2. DiamondTrap's name :" << DiamondTrap::getName() << std::endl;
}