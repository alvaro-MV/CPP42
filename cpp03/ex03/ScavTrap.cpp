#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Scav") {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->type_trap = "ScavTrap";
	std::cout << "ScavTrap " << this->name 
          << " has entered the arena, guarding the gates!!" << std::endl;
};

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->type_trap = "ScavTrap";
	std::cout << "ScavTrap " << this->name 
          << " has entered the arena, guarding the gates!!" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& sv) {
	this->name = sv.name;
	this->energyPoints = sv.energyPoints;
	this->hitPoints = sv.hitPoints;
	this->attackDamage = sv.attackDamage;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& sv): ClapTrap(sv.name) {
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

unsigned int ScavTrap::getHitPoints() {
	return (this->hitPoints);
}