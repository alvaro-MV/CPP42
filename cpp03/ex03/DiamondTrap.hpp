#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& st);
		ScavTrap& operator=(const ScavTrap& sv);
		~ScavTrap();

		void guardGate(void);
		unsigned int getHitPoints();
};

#endif