#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB {

	std::string name;
	Weapon*		w;

	public:
		HumanB(std::string name);
		HumanB(const HumanB &b);
		HumanB &operator=(const HumanB& b);
		~HumanB();

		void attack();
		void setWeapon(Weapon &w);
};

#endif