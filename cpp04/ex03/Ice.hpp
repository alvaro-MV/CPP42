#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {
    protected:
        std::string type;

    public:
        Ice();
        Ice(Ice& a);
        Ice &operator=(Ice &other);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif