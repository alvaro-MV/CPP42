#include "WrongCat.hpp"

WrongCat::WrongCat() {

	this->type = "WrongCat";
	std::cout << "WrongCat created." << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) {
	this->type = wrongCat.type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat) {
	this->type = wrongCat.type;
	return (*this);
}

WrongCat::~WrongCat() {

	std::cout << "WrongCat destroyed." << std::endl;
}

void WrongCat::makeSound(void) const{
	std::cout << type << ": wrong miau wrong miau " << std::endl;
}