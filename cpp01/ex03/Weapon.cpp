#include "Weapon.hpp"

Weapon::Weapon() {
	this->type = "";
}

const std::string &Weapon::getType() {
	return (this->type);
}

Weapon::~Weapon() {

}

void Weapon::setType(std::string type) {
	this->type = type;
}


const Weapon &Weapon::operator=(const Weapon &w) {
	if (this != &w)
		this->type = w.type;
	return (*this);
}