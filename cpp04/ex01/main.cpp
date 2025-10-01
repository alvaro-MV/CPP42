#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void line(const char* t){ std::cout << "\n==== " << t << " ====\n"; }

static void showIdea(const Animal& a, int idx){
    std::cout << "[check] idea[" << idx << "]: ";
    a.getIdea(idx); // tus Dog/Cat ya imprimen el contenido o mensaje de error
}

int main(){
    line("1) Deep copy via copy-ctor (Dog)");
    Dog d1;
    d1.setIdea(0, "hueso");
    d1.setIdea(1, "pelota");
    Dog d2(d1);                    // copia profunda
    d2.setIdea(0, "sillon");       // cambiar copia no debe afectar original
    std::cout << "d1 vs d2 idea[0]\n";
    showIdea(d1, 0);               // esperado: "hueso"
    showIdea(d2, 0);               // esperado: "sillon"
    std::cout << "d1 vs d2 idea[1]\n";
    showIdea(d1, 1);               // "pelota"
    showIdea(d2, 1);               // "pelota"

    line("2) Deep copy via operator= (Cat)");
    Cat c1; c1.setIdea(5, "sillon");
    Cat c2; c2.setIdea(5, "temporal");
    c2 = c1;                       // copia profunda por asignacion
    c2.setIdea(5, "raton");
    std::cout << "c1 vs c2 idea[5]\n";
    showIdea(c1, 5);               // "sillon"
    showIdea(c2, 5);               // "raton"

    line("3) Self-assignment (no debe romper nada ni filtrar memoria)");
    d1 = d1;
    c1 = c1;

    line("4) Polimorfismo: array heterogeneo de Animal* y borrado virtual");
    Animal* zoo[6];
    for (int i = 0; i < 6; ++i){
        zoo[i] = (i % 2 == 0) ? static_cast<Animal*>(new Dog())
                              : static_cast<Animal*>(new Cat());
        zoo[i]->makeSound();
    }
    // set/get ideas via interfaz polimorfica
    zoo[0]->setIdea(99, "ultima-idea");
    showIdea(*zoo[0], 99);
    // casos borde
    zoo[1]->getIdea(-1);
    zoo[1]->getIdea(100);

    for (int i = 0; i < 6; ++i) delete zoo[i];

    line("5) Copias encadenadas");
    Dog a; a.setIdea(2, "A2");
    Dog b; b = a;                  // b: A2
    Dog e(b);                      // e: A2
    b.setIdea(2, "B2");
    std::cout << "a,b,e idea[2]\n";
    showIdea(a, 2);                // A2
    showIdea(b, 2);                // B2
    showIdea(e, 2);                // A2

    line("Fin ex01");
    return 0;
}