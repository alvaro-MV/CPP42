#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal.";
	std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal& animal) {
	this->type = animal.type;
}

Animal& Animal::operator=(const Animal& animal) {
	this->type = animal.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destroyed." << std::endl;
}
