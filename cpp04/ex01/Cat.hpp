#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {

	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat& cat);
		Cat& operator=(const Cat& cat);
		~Cat();

		void makeSound(void) const;
		void getIdea(int idx) const;
		void setIdea(int idx, std::string idea);
};

#endif