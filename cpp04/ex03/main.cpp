#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


int main()
{
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
    // Character *Boboooo = static_cast<Character*>(bob);
    // Character *Meeee = static_cast<Character*>(me);
    // *Boboooo = *Meeee;


    std::cout << "\n<======= BOB USING =========>\n" << std::endl;
    std::cout << "el 0: ", bob->use(0, *me);
    std::cout << "El 1: ", bob->use(1, *me);
    bob->unequip(0);
    bob->use(0, *me);
    delete bob;
    delete me;
    delete src;
    return 0;
}  