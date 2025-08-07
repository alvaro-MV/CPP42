#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &w)
{
	this->w = &w;
}

HumanB::~HumanB() {
	
}

HumanB &HumanB::operator=(const HumanB& a) {
	this->name = a.name;
	this->w = a.w;
	return (*this);
}

void HumanB::attack()
{
	std::cout << this->name 
	<< "  attacks with their " 
	<< this->w->getType() << std::endl;
}