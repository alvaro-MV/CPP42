#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat: public Animal {

	public:
		Cat();
		Cat(const Cat& cat);
		Cat& operator=(const Cat& cat);
		~Cat();

		void makeSound(void) const;
};

#endif