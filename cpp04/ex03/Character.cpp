#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : name("default")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    std::cout << "Character " << name << " created." << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &c) : name(c.name)
{
    std::cout << "Pero porque entras aqui pedazo de cabron" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (c.inventory[i])
            inventory[i] = appendMatArray(&globalMa, c.inventory[i]->clone());
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
            if (other.inventory[i]) {
                inventory[i] = appendMatArray(&globalMa, other.inventory[i]->clone());
            }

        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m || m->equip('r'))
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            if (!isInMatArray(&globalMa, m))
                appendMatArray(&globalMa, m);
            inventory[i] = m->clone();
            std::cout << "Equipped materia of type " << m->getType() << " in slot " << i << std::endl;
            m->equip('w');
            return;
        }
    }
    std::cout << "Inventory full, cannot equip materia of type " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->not_equip('w');
    AMateria* temp = inventory[idx];
    inventory[idx] = NULL;
    std::cout << "Unequipped materia of type " << temp->getType() << " from slot " << idx << std::endl;
    std::cout << "AMateria " << temp->getType() << " is now on the floor (not deleted)" << std::endl;
    //delete temp;
}


void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}
