#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA {

	std::string name;
	Weapon&		w;

	public:
		HumanA(std::string name, Weapon &w);
		HumanA(const HumanA &a);
		HumanA &operator=(const HumanA& a);
		~HumanA();
		void attack();
};

#endif