#include "ClapTrap.hpp"

int	main(void) {

	ClapTrap ct("robototo");

	ct.attack("Rabototo");
	ct.takeDamage(5);
	ct.beRepaired(4);
	ct.takeDamage(6);
	ct.takeDamage(3);
	ct.beRepaired(4);
}
