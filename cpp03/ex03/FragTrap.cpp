
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("frag") {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->type_trap = "FragTrap";
	std::cout << "FragTrap " << name << " is here, ready to throw grenades everywhere!!" << std::endl;
};

FragTrap::FragTrap(std::string name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->type_trap = "FragTrap";
	std::cout << "FragTrap " << name << " is here, ready to throw grenades everywhere!!" << std::endl;
};

unsigned int FragTrap::getAttackDamage() {
	return (attackDamage);
}

FragTrap& FragTrap::operator=(const FragTrap& sv) {
	this->name = sv.name;
	this->energyPoints = sv.energyPoints;
	this->hitPoints = sv.hitPoints;
	this->attackDamage = sv.attackDamage;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& sv): ClapTrap(sv.name) {
	this->energyPoints = sv.energyPoints;
	this->hitPoints = sv.hitPoints;
	this->attackDamage = sv.attackDamage;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name 
              << " waves goodbye with one last HIGH FIVE before shutting down... ✋🤖" 
              << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name 
          << " yells: HIGH FIVE, GUYS!! ...don’t leave me hanging 😢" 
          << std::endl;
}

unsigned int FragTrap::getHitPoints() {
	return (this->hitPoints);
}