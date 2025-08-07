#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA {

	std::string name;
	Weapon&		w;

	public:
		HumanA(std::string name, Weapon &w): name(name), w(w) {};
		HumanA(const HumanA &a): name(a.name), w(a.w) {};
		HumanA &operator=(const HumanA& a);
		~HumanA();
		void attack();
};

#endif