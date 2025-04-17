#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap(std::string name): ClapTrap(name) {
			this->hitPoints = 100;
			this->energyPoints = 50;
			this->attackDamage = 20;
			this->type_trap = "ScavTrap";
			std::cout << "ScavTrap " << name << " ready for battle!!" << std::endl;
		};
		ScavTrap(const ScavTrap& st);
		ScavTrap& operator=(const ScavTrap& sv);
		~ScavTrap();

		void guardGate(void);
};

#endif