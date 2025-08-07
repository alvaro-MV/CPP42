#include "Zombie.hpp"

int	main(void)
{
	randomChump("Foo");
	
	Zombie zom = Zombie("Fee");
	zom.announce();
	
	Zombie *z = newZombie("Faa");
	z->announce();
	delete z;
}