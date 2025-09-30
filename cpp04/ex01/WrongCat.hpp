#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat: public WrongAnimal {

	private:
	public:
		WrongCat();
		WrongCat(const WrongCat& cat);
		WrongCat& operator=(const WrongCat& cat);
		~WrongCat();

		void makeSound(void) const;
};

#endif