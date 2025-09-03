
#ifndef CHARACTER_H
# define CHARACTER_H

#include <string>
#include "ICharacter.hpp"

class AMateria;

class Character: public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];


    public:
        Character();
        Character(std::string name);
        Character(const Character &c);
        Character &operator=(const Character &other);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif