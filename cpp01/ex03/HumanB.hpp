#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB {

	std::string name;
	Weapon*		w;

	public:
		HumanB(std::string name): name(name), w(NULL) {};
		HumanB(const HumanB &b): name(b.name), w(b.w) {};
		HumanB &operator=(const HumanB& b);
		~HumanB();

		void attack();
		void setWeapon(Weapon &w);
};

#endif