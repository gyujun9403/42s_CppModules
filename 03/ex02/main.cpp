#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap tom("tom");
	FragTrap jack("jack");
	std::cout << "------------------------------------------" << std::endl;

	jack.highFivesGuys();
	tom.setAttackDamage(2);
	std::cout << "tom spell damage buff!! tom's attack damage is " << tom.getAttackDamage() << std::endl;
	tom.attack("jack");
	jack.takeDamage(tom.getAttackDamage());
	jack.attack("tom");
	tom.takeDamage(jack.getAttackDamage());
	std::cout << "tom's HP is " << tom.getHitPoint() << "." << std::endl;
	std::cout << "jack's HP is " << jack.getHitPoint() << "." << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		jack.beRepaired(1);
	}
	std::cout << "jack HP :" << jack.getHitPoint() << std::endl;

	std::cout << "\ntom takes HERO damage buff!!" << std::endl;
	tom.setAttackDamage(4294967295);
	std::cout << "tom's attack damage is " << tom.getAttackDamage() << std::endl;
	tom.attack("jack");
	jack.takeDamage(tom.getAttackDamage());
	std::cout << "jack's HP is " << jack.getHitPoint() << "." << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	return (0);
}