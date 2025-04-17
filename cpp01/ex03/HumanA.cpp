#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name 
	<< "  attacks with their " 
	<< this->w.getType() << std::endl;
}