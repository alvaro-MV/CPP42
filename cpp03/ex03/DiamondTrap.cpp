#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), ScavTrap(), FragTrap()  {
    name = "default";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name
          << " has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"),  ScavTrap(name), FragTrap(name) {
    this->name = name;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name
          << "Second const has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& st) {
    hitPoints = st.hitPoints;
    energyPoints = st.energyPoints;
    attackDamage = st.attackDamage;
    std::cout << "DiamondTrap " << this->name
          << "Copy: has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& st) {
    hitPoints = st.hitPoints;
    energyPoints = st.energyPoints;
    attackDamage = st.attackDamage;
    std::cout << "DiamondTrap " << this->name
          << "Assign: has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name
          << " has arrived — shining with power, guarding the gates, and ready to explode things in style! 💎🤖"
          << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "My name is: " << this->name << " and my ClapTrap name is: " << ClapTrap::name << std::endl;
}