#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {

	protected:
		std::string 	name;
		std::string		type_trap = "ClapTrap";
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

	
	public:

		ClapTrap() {};
		ClapTrap(std::string name): name(name), 
									hitPoints(10), 
									energyPoints(10),
									attackDamage(0) {
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