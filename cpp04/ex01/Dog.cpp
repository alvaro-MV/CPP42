#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain("guau");
	std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog& dog): Animal(dog) {
	if (this != &dog)
		brain = new Brain(*dog.brain);
	this->type = dog.type;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain) delete brain;
        brain = new Brain(*other.brain); // deep copy
    }
    return *this;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound(void) const{
	std::cout << type << ": guau guau" << std::endl;
}

void Dog::getIdea(int idx) const {
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

void Dog::setIdea(int idx, std::string idea) {
	if (idx < 0 || idx > 99)
		std::cout << "idea " << idx << ": My " << this->getType()
		<< " brain don't posses that idea." << std::endl;
	else
		this->brain->set_idea_idx(idx, idea);
}