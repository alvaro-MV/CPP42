#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {

	protected:
		std::string type;
	
		public:
			Animal();
			Animal(const Animal& animal);
			Animal& operator=(const Animal& animal);
			virtual ~Animal();

			virtual void makeSound(void) const = 0;
			virtual void getIdea(int idx) const = 0;
			virtual void setIdea(int idx, std::string idea) = 0;;
			virtual std::string getType(void) const = 0;
};

#endif