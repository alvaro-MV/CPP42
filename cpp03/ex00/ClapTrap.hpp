#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {

	private:
		std::string 	name;
		unsigned int	hitPoints = 10;
		unsigned int	energyPoints = 10;
		unsigned int	attackDamage = 0;
	
	public:

		ClapTrap(std::string name): name(name) {
			std::cout << "ClapTrap " << this->name << " ready for battle!!" << std::endl;
		};
		ClapTrap(const ClapTrap& ct);
		ClapTrap& operator=(const ClapTrap& ct);
		~ClapTrap();


		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif