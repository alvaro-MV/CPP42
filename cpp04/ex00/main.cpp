#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void line(const char* title) {
    std::cout << "\n========== " << title << " ==========\n";
}

int main() {
    line("1) Polimorfismo basico");
    const Animal* meta = new Animal();      // permitido en ex00
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();

    std::cout << "j->getType(): " << j->getType() << "\n";
    std::cout << "i->getType(): " << i->getType() << "\n";
    i->makeSound(); // Cat
    j->makeSound(); // Dog
    meta->makeSound(); // Animal

    line("2) Borrado por puntero a base (debe llamar dtor derivado)");
    delete meta; // ~Animal
    delete i;    // ~Cat -> ~Animal, solo si ~Animal es virtual
    delete j;    // ~Dog -> ~Animal

    line("3) Copia y asignacion (visibles por mensajes)");
    Cat c1;
    Cat c2(c1);            // copy ctor
    Cat c3; c3 = c1;       // operator=
    c1.makeSound();

    Dog d1;
    Dog d2(d1);            // copy ctor
    Dog d3; d3 = d1;       // operator=
    d2.makeSound();

    line("4) Wrong* (sin virtual): debe oirse sonido de WrongAnimal");
    const WrongAnimal* w = new WrongCat();
    std::cout << "w->getType(): " << w->getType() << "\n";
    w->makeSound();  // debería imprimir sonido de WrongAnimal (no de WrongCat)
    delete w;        // sin dtor virtual: en ex00 no hay recursos, objetivo es didáctico

    line("5) Polimorfismo en bucle (Animal*)");
    const Animal* zoo[4];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Dog();
    zoo[3] = new Cat();

    for (int k = 0; k < 4; ++k) {
        std::cout << k << ") " << zoo[k]->getType() << " -> ";
        zoo[k]->makeSound();
    }
    for (int k = 0; k < 4; ++k) delete zoo[k];

    line("6) Self-assignment");
    Dog dd1; dd1 = dd1;
    Cat cc1; cc1 = cc1;

    line("Fin ex00");
    return 0;
}

/* 
	- virtual destructor, para evitar comportamientos indefinidos.
	- necesidad de declarar punteros para trabajar con polimorfismo.
	- virtual para las funciones miembros
	- 
*/