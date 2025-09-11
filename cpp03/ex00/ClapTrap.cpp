#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"),
									  hitPoints(10),
									  energyPoints(10),
									  attackDamage(0) {
	std::cout << YELLOW << "ClapTrap " << this->name << " ready for battle!!" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name),
									  hitPoints(10),
									  energyPoints(10),
									  attackDamage(0) {
	std::cout << YELLOW << "ClapTrap " << this->name << " ready for battle!!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct) {
	this->name = ct.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct) {
	this->name = ct.name;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap " << this->name << " leaves this world." << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->hitPoints)
	{
		std::cout << GREEN << name << " can not attack, has died." << RESET << std::endl;
		return ;
	}
	if (!energyPoints) {
		std::cout << GREEN << "Not enough energy points." << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ClapTrap " << this->name
	<< " attacks " << target 
	<< ", causing " << this->attackDamage
	<<" points of damage!" << RESET << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {

	std::cout << BLUE << "ClapTrap " << this->name
	<< " takes " << amount 
	<< " hit points. ";

	if (amount >= this->hitPoints)
	{
		std::cout << this->name << " has died.";
		this->hitPoints = 0;
	}
	else
		this->hitPoints -= amount;
	std::cout << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << MAGENTA << name << "can not be repaired, has died." << std::endl;
		return ;
	}
	std::cout << MAGENTA << "ClapTrap " 
	<< this->name << " has recovered "
	<< amount << " hit points." << RESET << std::endl;

	this->hitPoints += amount;
}
