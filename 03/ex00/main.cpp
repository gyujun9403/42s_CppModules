#include "ClapTrap.hpp"

int main()
{
	ClapTrap tom("Tom");
	ClapTrap tam("Tam");
	std::cout << "------------------------------------------" << std::endl;

	tom.setAttackDamage(2);
	std::cout << "tom spell damage buff!!. tom's attack damage is " << tom.getAttackDamage() << std::endl;

	tom.attack("Tam");
	tam.takeDamage(tom.getAttackDamage());
	std::cout << "tam spell heal to himself." << std::endl;
	int tempHP = tam.getHitPoint();
	tam.beRepaired(1);
	std::cout << "tam's HP become " << tempHP << " to " << tam.getHitPoint() << "." << std::endl;
	std::cout << "\ntom takes HERO damage buff!!." << std::endl;
	tom.setAttackDamage(4294967295);
	std::cout << "tom's attack damage is " << tom.getAttackDamage() << std::endl;
	tom.attack("Tam");
	tam.takeDamage(tom.getAttackDamage());
	std::cout << "tam's HP is " << tam.getHitPoint() << "." << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	return (0);
}