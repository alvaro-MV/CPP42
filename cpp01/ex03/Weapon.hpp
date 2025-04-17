#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {

	public:
		Weapon();
		Weapon(std::string type_input): type(type_input) {};
		Weapon(const Weapon &w): type(w.type) {};
		const Weapon &operator=(const Weapon &w) {
			if (this != &w)
			this->type = w.type;
			return (*this);
		};
		~Weapon() = default;

		const std::string &getType();
		void setType(std::string type);
	
	private:
		std::string type;
};

#endif