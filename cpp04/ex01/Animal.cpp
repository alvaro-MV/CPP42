#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal.";
	std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal& animal) {
	if (this != &animal)
		this->type = animal.type;
}

Animal& Animal::operator=(const Animal& animal) {
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destroyed." << std::endl;
}

void Animal::makeSound(void) const{
	std::cout << "Generic Animal growl" << std::endl;
}

std::string Animal::getType(void) const{
	return (this->type);
}

// void Animal::getIdea(int idx) const {
// 	std::cout << "Have I brain?" << std::endl;
// }

// void Animal::setIdea(int idx, std::string idea) {
// 	std::cout << "Have I brain?" << std::endl;
// }