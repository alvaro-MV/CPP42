#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;



class AMateria {
    protected:
        bool _equiped;
        std::string type;

    public:
        AMateria(std::string const & type);
        AMateria(const AMateria& a);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();

        std::string const & getType() const;
        bool equip(char rw);
        bool not_equip(char rw);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

typedef struct matArray {
    AMateria    **arr;
    size_t      cap;
    size_t      size;
} matArray;

void    initMatArray(matArray *arr);
AMateria    *appendMatArray(matArray *arr, AMateria* mat);
AMateria    *appendMatArray(matArray *arr, AMateria* mat);
bool isInMatArray(matArray *arr, AMateria *mat);

extern matArray globalMa;


#endif