#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource created" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &m)
{
	int this_i = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m.inventory[i])
		{
			inventory[this_i] = m.inventory[i]->clone();
		}
		else
			inventory[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource &m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m.inventory[i])
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = m.inventory[i]->clone();
		}
		else
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
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

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return;
		}
	}
	// If we reach here, the inventory is full; do nothing
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return NULL; // If no matching materia is found
}