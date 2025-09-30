#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal.";
	std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) {
	this->type = animal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal) {
	this->type = animal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal destroyed." << std::endl;
}

void WrongAnimal::makeSound(void) const{
	std::cout << "Generic wrong Animal growl" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return (this->type);
}