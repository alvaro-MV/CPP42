#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << "Insufficient number of zombies requested." << std::endl;
		return (NULL);
	}
	if (name.empty()) {
		name = "Default";
	}
	Zombie *zhorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zhorde[i] = Zombie(name);
	return (zhorde);
}
