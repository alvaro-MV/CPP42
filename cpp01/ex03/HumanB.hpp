#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB {

	std::string name;
	Weapon*		w;

	public:
		HumanB(std::string name): name(name), w(nullptr) {};
		HumanB(const HumanB &b): name(name), w(b.w) {};
		HumanB &operator=(const HumanB& b) {
			this->name = b.name;
			this->w = b.w;
			return (*this);
		};
		~HumanB() = default;

		void attack();
		void setWeapon(Weapon &w);
};

#endif