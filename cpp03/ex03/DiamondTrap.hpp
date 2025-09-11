#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& st);
		DiamondTrap& operator=(const DiamondTrap& sv);
		~DiamondTrap();

		unsigned int getHitPoints();

	private:
		std::string name;
};

#endif