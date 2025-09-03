
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {
    protected:
        std::string type;

    public:
        Cure();
        Cure(Cure& a);
        Cure &operator=(Cure &other);
        ~Cure();

        std::string const & getType() const;
        AMateria* clone() const override;
        void use(ICharacter& target)  override;
};

#endif