#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>
#include <new>

class Zombie {

	private:
		std::string name;

	public:
		Zombie(std::string name);
		// Zombie(const Zombie &zombie);
		// Zombie &operator=(const Zombie &zombie);
		~Zombie();

		void announce(void);
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif