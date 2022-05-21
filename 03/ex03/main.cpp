#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("test");

	dt.whoAmI();
	dt.attack("gyeon");
	std::cout << "getAttackDamage : " << dt.getAttackDamage() << std::endl;
	std::cout << "getEnergyPoint : " << dt.getEnergyPoint() << std::endl;
	std::cout << "getHitPoint : " << dt.getHitPoint() << std::endl;
}