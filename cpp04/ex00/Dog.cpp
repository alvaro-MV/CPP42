#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog& dog) {
	this->type = dog.type;
}

Dog& Dog::operator=(const Dog& dog) {
	this->type = dog.type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound(void) const{
	std::cout << type << ": guau guau" << std::endl;
}