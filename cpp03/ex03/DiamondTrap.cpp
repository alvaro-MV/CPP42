#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), ScavTrap(), FragTrap()  {
    name = "default";
    hitPoints = 10;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name
          << " has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"),  ScavTrap(name), FragTrap(name) {
    this->name = name;
    hitPoints = 10;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name
          << ": Second const has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& st): ClapTrap(st.name + "_clap_name"), ScavTrap(st.name), FragTrap(st.name) {
    hitPoints = 10;
    energyPoints = st.energyPoints;
    attackDamage = st.attackDamage;
    std::cout << "DiamondTrap " << this->name
          << "Copy: has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& st) {
    hitPoints = 10;
    energyPoints = st.energyPoints;
    attackDamage = st.attackDamage;
    std::cout << "DiamondTrap " << this->name
          << "Assign: has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap: " << this->name
          << " my shine has expired"
          << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "My name is: " << this->name << " and my ClapTrap name is: " << ClapTrap::name << std::endl;
}