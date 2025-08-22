#include "Zombie.hpp"

int	main(void)
{
	int N = 4;
	Zombie *zhorde = zombieHorde(N, "Germán");
	for (int i = 0; i < N; i++)
		zhorde[i].announce();
	delete[] zhorde;
}