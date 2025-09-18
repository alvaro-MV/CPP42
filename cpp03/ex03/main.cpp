#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap trap("Raton");

	std::cout << "\n-----------------------------------------------\n" << std::endl;

	trap.whoAmI();

	for (int i = 0; i < 3; i++)
		trap.attack("RATAAT");
	std::cout << "El ataque de mi bicho es teniendo en cuenta que el ataque de FragTrap es 30 --> " << trap.getAttackDamage() << std::endl;
	std::cout << "\n-----------------------------------------------\n" << std::endl;
	return (0);
}