#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, private FragTrap {

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& st);
		DiamondTrap& operator=(const DiamondTrap& st);
		void whoAmI();
		~DiamondTrap();

	private:
		std::string name;
};

#endif