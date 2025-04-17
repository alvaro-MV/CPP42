#include "Zombie.hpp"

int	main(void)
{
	Zombie *zhorde = zombieHorde(4, "Curro");
	for (int i = 0; i < 4; i++)
		zhorde[i].announce();
	delete[] zhorde;
}