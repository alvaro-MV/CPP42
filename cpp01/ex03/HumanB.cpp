#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &w)
{
	this->w = &w;
}

void HumanB::attack()
{
	std::cout << this->name 
	<< "  attacks with their " 
	<< this->w->getType() << std::endl;
}