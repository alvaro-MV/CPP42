#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice& a) : AMateria(a) {
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice &other){
    (void) other;
    std::cout << "Ice copy asignment called" << std::endl;
    return(*this);
}

Ice::~Ice(){
    std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
    return (new Ice());
}