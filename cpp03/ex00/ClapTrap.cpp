#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap& ct) {
	this->name = ct.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct) {

	this->name = ct.name;
	return (*this);
}

ClapTrap::~ClapTrap() {

}

void ClapTrap::attack(const std::string& target) {

	if (!energyPoints)
		std::cout << "Not enough energy points." << std::endl;
	if (!this->hitPoints)
		return ;
	std::cout << "ClapTrap " << this->name
	<< " attacks " << target 
	<< ", causing " << this->attackDamage
	<<" points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {

	std::cout << "ClapTrap " << this->name
	<< " takes " << amount 
	<< " hit points" << std::endl;

	if (amount >= this->hitPoints)
	{
		std::cout << this->name << " has died." << std::endl;
		this->hitPoints = 0;
	}
	else
		this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << name << " has died." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " 
	<< this->name << " has recovered "
	<< amount << " hit points." << std::endl;

	this->hitPoints += amount;
}
