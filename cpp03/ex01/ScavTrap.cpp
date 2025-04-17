#include "ScavTrap.hpp"

ScavTrap& ScavTrap::operator=(const ScavTrap& sv) {
	this->name = sv.name;
	this->energyPoints = sv.energyPoints;
	this->hitPoints = sv.hitPoints;
	this->attackDamage = sv.attackDamage;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& sv) {

	this->name = sv.name;
	this->energyPoints = sv.energyPoints;
	this->hitPoints = sv.hitPoints;
	this->attackDamage = sv.attackDamage;
}

ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap " << this->name << " goes to garbage." << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}