#include "Cat.hpp"

Cat::Cat() {

	this->type = "Cat";
	std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat& cat) {
	this->type = cat.type;
}

Cat& Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	return (*this);
}

Cat::~Cat() {

	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound(void) const{
	std::cout << type << ": miau miau" << std::endl;
}