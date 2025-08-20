#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>
#include <new>
#include <cstring>

class Zombie {

	std::string name;

	public:
		Zombie();
		Zombie(std::string name);
		Zombie &operator=(const Zombie &zombie);
		~Zombie();

		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif