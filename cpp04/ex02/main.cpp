#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void line(const char* t){ std::cout << "\n==== " << t << " ====\n"; }

static void checkIdea(const Animal& a, int idx, const char* who){
    std::cout << who << " idea[" << idx << "]: ";
    a.getIdea(idx); // tus Dog/Cat ya imprimen el contenido o el error
}

int main(){
    line("1) Deep copy via copy-ctor (Dog)");
    Dog d1;
    d1.setIdea(0, "hueso");
    d1.setIdea(1, "pelota");

    Dog d2(d1);                   // copia profunda por ctor
    d2.setIdea(0, "sofa");        // cambiar copia no afecta original

    checkIdea(d1, 0, "d1");       // esperado: "hueso"
    checkIdea(d2, 0, "d2");       // esperado: "sofa"
    checkIdea(d1, 1, "d1");       // "pelota"
    checkIdea(d2, 1, "d2");       // "pelota"

    line("2) Deep copy via operator= (Cat)");
    Cat c1; c1.setIdea(5, "sillon");
    Cat c2; c2.setIdea(5, "temporal");
    c2 = c1;                      // copia profunda por asignacion
    c2.setIdea(5, "raton");
    checkIdea(c1, 5, "c1");       // "sillon"
    checkIdea(c2, 5, "c2");       // "raton"

    line("3) Self-assignment (no debe romper nada ni filtrar memoria)");
    d1 = d1;
    c1 = c1;

    line("4) Polimorfismo: array heterogeneo Animal* y borrado virtual");
    Animal* zoo[6];
    for (int i = 0; i < 6; ++i){
        if (i % 2 == 0) zoo[i] = new Dog();
        else            zoo[i] = new Cat();
        zoo[i]->makeSound();
    }

    // set/get ideas via interfaz polimorfica
    zoo[0]->setIdea(99, "ultima-idea-dog");
    checkIdea(*zoo[0], 99, "zoo[0]"); // debe mostrar "ultima-idea-dog"

    // casos borde
    zoo[1]->getIdea(-1);
    zoo[1]->getIdea(100);

    for (int i = 0; i < 6; ++i) delete zoo[i];

    line("5) Copias encadenadas y aislamiento de estados");
    Dog a; a.setIdea(2, "A2");
    Dog b; b = a;                  // deep copy: b: A2
    Dog e(b);                      // deep copy: e: A2
    b.setIdea(2, "B2");
    checkIdea(a, 2, "a");          // A2
    checkIdea(b, 2, "b");          // B2
    checkIdea(e, 2, "e");          // A2

    line("Fin ex03");
    return 0;
}
