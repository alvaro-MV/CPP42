#include "Weapon.hpp"

Weapon::Weapon(std::string type_input): type(type_input) {};

Weapon::Weapon(const Weapon &w): type(w.type) {};

Weapon::Weapon() {
	this->type = "";
}

const std::string &Weapon::getType() {
	return (this->type);
}

Weapon::~Weapon() {
	std::cout << "Weapon destructor called" << std::endl;
}

void Weapon::setType(std::string type) {
	this->type = type;
}


const Weapon &Weapon::operator=(const Weapon &w) {
	if (this != &w)
		this->type = w.type;
	return (*this);
}