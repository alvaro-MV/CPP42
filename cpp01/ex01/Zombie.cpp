#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie &Zombie::operator=(const Zombie &z) {
	this->name = z.name;
	return (*this);
}
Zombie::~Zombie() {
	std::cout << this->name << " DEAD" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}