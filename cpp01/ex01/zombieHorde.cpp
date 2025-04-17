#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zhorde = new Zombie[N];
	Zombie z(name);
	for (int i = 0; i < N; i++)
		zhorde[i] = z;
	return (zhorde);
}
