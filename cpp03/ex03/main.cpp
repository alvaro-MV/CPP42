#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap trap("Raton");

	DiamondTrap otro(trap);
	trap.whoAmI();


	for (int i = 0; i < 3; i++)
		trap.attack("RATAAT");
	std::cout << "El ataque de mi bicho es teniendo en cuenta que el ataque de FragTrap es 30 --> " << trap.getAttackDamage() << std::endl;
	return (0);
}