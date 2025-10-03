#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"



extern void    initMatArray(matArray *arr) {
    arr->cap = 4;
    arr->size = 0;
    arr->arr = new(AMateria*[4]);
}

AMateria    *appendMatArray(matArray *arr, AMateria* mat) {
    if (arr->cap == arr->size)
    {
        AMateria** tmp = arr->arr;
        size_t double_cap = arr->cap * 2;
        arr->arr = new AMateria*[double_cap];
        for (size_t i = 0; i < arr->cap; i++)
            arr->arr[i] = tmp[i];
        delete[] tmp;
        arr->cap *= 2;
    }
    arr->arr[arr->size] = mat;
    arr->size++;
    return (mat);
}

void    deleteMatArray(matArray *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        if (arr->arr[i])
            delete arr->arr[i];
    }
    delete[] arr->arr;
}

bool isInMatArray(matArray *arr, AMateria *mat) {
    for (size_t i = 0; i < arr->size; i++) {
        if (arr->arr[i] == mat)
            return (true);
    }
    return false;
}

matArray globalMa = { NULL, 0, 0 };   // ← definición (reserva memoria)

int main()
{

    std::cout << "\n<======= MatArrayCreation =========>" << std::endl;
    initMatArray(&globalMa);

    std::cout << "\n<======= materiasource creation =========>" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "\n<======= ME CHARACTER CREATION =========>\n" << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n<======= BOB CHARACTER CREATION =========>\n" << std::endl;
    ICharacter* bob = new Character("bob");
    me->unequip(1);
    bob->equip(tmp);
    Character *Boboooo = static_cast<Character*>(bob);
    Character *Meeee = static_cast<Character*>(me);
    *Boboooo = *Meeee;


    std::cout << "\n<======= BOB USING =========>\n" << std::endl;
    std::cout << "el 0: ", bob->use(0, *me);
    std::cout << "El 1: ", bob->use(1, *me);
    bob->unequip(0);
    bob->use(0, *me);
    deleteMatArray(&globalMa);
    delete bob;
    delete me;
    delete src;
    return 0;
}  