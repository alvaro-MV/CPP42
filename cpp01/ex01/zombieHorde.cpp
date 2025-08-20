#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zhorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zhorde[i] = Zombie(name);
	return (zhorde);
}
