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

        std::string const & getType() const;
        AMateria* clone() const override;
        void use(ICharacter& target) override;
};

#endif