#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap() constructor called. " << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "~FragTrap() destructor called. " << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
	return (*this);
}

void FragTrap::attack(std::string const & target)
{
	if (this->energyPoint_ <= 0)
	{
		std::cout << "FragTrap " << this->name_ << " NOT ENOUGH ENERGY!!!" << std::endl;
	}
	else
	{
		--this->energyPoint_;
		std::cout << "FragTrap " << name_ << " attack " << target << ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
	}
}

FragTrap::FragTrap(std::string name)
{
	this->name_ = name;
	this->hitPoint_ = INITIAL_HIT_POINT;
	this->attackDamage_ = INITIAL_ATTACK_DAMAGE;
	this->energyPoint_ = INITIAL_ENERGY_POINT;
	std::cout << "FragTrap(name) constructor called. " << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->energyPoint_ <= 0)
	{
		std::cout << "FragTrap " << this->name_ << " NOT ENOUGH ENERGY!!!" << std::endl;
	}
	else
	{
		--this->energyPoint_;
		std::cout << this->name_ << " give high fives with others." << std::endl;
	}
}

int FragTrap::getInitHP() const
{
	return this->INITIAL_HIT_POINT;
}