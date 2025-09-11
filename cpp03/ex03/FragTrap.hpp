#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& st);
		FragTrap& operator=(const FragTrap& sv);
		~FragTrap();

		void highFivesGuys(void);
		unsigned int getHitPoints();
};

#endif