#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {

	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog& dog);
		Dog& operator=(const Dog& dog);
		~Dog();

		void makeSound(void) const;
		void getIdea(int idx) const;
		void setIdea(int idx, std::string idea);
		std::string getType(void) const;
};

#endif