#include "HumanA.hpp"

HumanA::~HumanA() {
	
}

HumanA &HumanA::operator=(const HumanA& a) {
	this->name = a.name;
	this->w = a.w;
	return (*this);
}

void HumanA::attack()
{
	std::cout << this->name 
	<< "  attacks with their " 
	<< this->w.getType() << std::endl;
}