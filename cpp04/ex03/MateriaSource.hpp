#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include <string>

class AMateria;

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* inventory[4];

    public:
        MateriaSource();
        MateriaSource(MateriaSource& m);
        MateriaSource& operator=(MateriaSource& m);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif