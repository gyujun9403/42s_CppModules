#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap tom("Tom");
	ScavTrap tam("Tam");
	std::cout << "------------------------------------------" << std::endl;

	tam.guardGate();
	tom.setAttackDamage(2);
	std::cout << "tom spell damage buff!!. tom's attack damage is " << tom.getAttackDamage() << std::endl;
	tom.attack("Tam");
	tam.takeDamage(tom.getAttackDamage());
	//std::cout << "🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟" << std::endl;
	tam.attack("tom");
	tom.takeDamage(tam.getAttackDamage());
	std::cout << "tom's HP is " << tom.getHitPoint() << "." << std::endl;
	std::cout << "tam's HP is " << tam.getHitPoint() << "." << std::endl;
	std::cout << "\ntom takes HERO damage buff!!." << std::endl;
	tom.setAttackDamage(4294967295);
	std::cout << "tom's attack damage is " << tom.getAttackDamage() << std::endl;
	tom.attack("Tam");
	tam.takeDamage(tom.getAttackDamage());
	std::cout << "tam's HP is " << tam.getHitPoint() << "." << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	return (0);
}