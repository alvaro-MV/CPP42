#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure& a) : AMateria(a) {
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure &other){
    (void) other;
    std::cout << "Cure copy asignment called" << std::endl;
    return(*this);
}

Cure::~Cure(){
    std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    return (new Cure());
}