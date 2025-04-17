#include "Cat.hpp"

Cat::Cat() {

	this->type = "Cat";
	this->brain = new Brain("miau");
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
	delete this->brain;
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound(void) const{
	std::cout << type << ": miau miau" << std::endl;
}

void Cat::getIdea(int idx) const {
	if (idx < 0 || idx > 99)
		std::cout << "idea: " << idx << " "
		<< "My " << this->getType()
		<< " brain don't posses that idea." << std::endl;
	else
	{
		std::cout << "idea " << idx << ": " 
		<< this->brain->get_idea_idx(idx) << std::endl;
	}
}

void Cat::setIdea(int idx, std::string idea) {
	if (idx < 0 || idx > 99)
		std::cout << "My " << this->getType()
		<< " brain don't posses that idea." << std::endl;
	else
		this->brain->set_idea_idx(idx, idea);
}