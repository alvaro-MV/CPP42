#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {

	public:
		Weapon();
		Weapon(std::string type_input): type(type_input) {};
		Weapon(const Weapon &w): type(w.type) {};
		const Weapon &operator=(const Weapon &w);
		~Weapon();

		const std::string &getType();
		void setType(std::string type);
	
	private:
		std::string type;
};

#endif