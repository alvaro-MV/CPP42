#include "Cat.hpp"

Cat::Cat(): Animal() {

	this->type = "Cat";
	std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat& cat): Animal(cat) {
	// this->type = cat.type;
}

Cat& Cat::operator=(const Cat& cat) {
	if (this != &cat)
		Animal::operator=(cat);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound(void) const{
	std::cout << type << ": miau miau" << std::endl;
}