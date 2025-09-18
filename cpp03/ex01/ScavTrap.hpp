#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : ublic ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& st);
		ScavTrap& operator=(const ScavTrap& sv);
		~ScavTrap();

		virtual void attack(const std::string &target);
		void guardGate(void);
		unsigned int getHitPoints();
};

#endif