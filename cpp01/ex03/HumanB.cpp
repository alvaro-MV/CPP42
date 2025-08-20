#include "HumanB.hpp"


HumanB::HumanB(std::string name): name(name), w(NULL) {};

HumanB::HumanB(const HumanB &b): name(b.name), w(b.w) {};

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
	if (this->w == NULL) {
		std::cout << this->name 
		<< " has no weapon to attack with!" 
		<< std::endl;
		return;
	}
	std::cout << this->name 
	<< "  attacks with their " 
	<< this->w->getType() << std::endl;
}