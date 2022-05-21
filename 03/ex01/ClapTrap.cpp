#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap() constructor called. " << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "~ClapTrap() destructor called. " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->name_ = other.name_;
	this->attackDamage_ = other.attackDamage_;
	this->hitPoint_ = other.hitPoint_;
	this->energyPoint_  = other.energyPoint_;
	return (*this);
}

ClapTrap::ClapTrap(const std::string name)
{
	this->name_ = name;
	this->attackDamage_ = INITIAL_ATTACK_DAMAGE;
	this->hitPoint_ = INITIAL_HIT_POINT;
	this->energyPoint_  = INITIAL_ENERGY_POINT;
	std::cout << "ClapTrap(name) constructor called. " << std::endl;
}

// attack target to lose <attackDamage_>, cost 1 <energyPoint_>.
void ClapTrap::attack(std::string const & target)
{
	if (this->energyPoint_ <= 0)
	{
		std::cout << "ClapTrap " << this->name_ << " NOT ENOUGH ENERGY!!!" << std::endl;
	}
	else
	{
		--this->energyPoint_;
		std::cout << "ClapTrap " << name_ << " attack " << target << ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
	}
}

// take damage <amount>. so, lose <hitPoint_>.
void ClapTrap::takeDamage(unsigned int amount)
{
	long long temp;

	temp = (long long)this->hitPoint_ - (long long)amount;
	if (temp > 0)
		this->hitPoint_ = temp;
	else
		this->hitPoint_ = 0;
}

// repair <hitPoint_> <amount>, cost 1 energy point.
void ClapTrap::beRepaired(unsigned int amount)
{
	long long temp;

	if (this->energyPoint_ <= 0)
	{
		std::cout << "ClapTrap " << this->name_ << " NOT ENOUGH ENERGY!!!" << std::endl;
	}
	else
	{
		--this->energyPoint_;
		temp = (long long)amount + (long long)this->hitPoint_;
		if (temp > 4294967295LL)
			this->hitPoint_ = 4294967295U;
		else if (temp > getInitHP())
			this->hitPoint_ = getInitHP();
		else
			this->hitPoint_ = temp;
	}
}

std::string ClapTrap::getName()
{
	return (this->name_);
}

int ClapTrap::getHitPoint() const
{
	return this->hitPoint_;
}

int ClapTrap::getEnergyPoint() const
{
	return this->energyPoint_;
}

int ClapTrap::getAttackDamage() const
{
	return this->attackDamage_;
}

void ClapTrap::setAttackDamage(const unsigned int attackDamage)
{
	if (attackDamage > 2147483647)
		this->attackDamage_ = 2147483647;
	else
		this->attackDamage_ = attackDamage;
}

int ClapTrap::getInitHP() const
{
	return this->INITIAL_HIT_POINT;
}