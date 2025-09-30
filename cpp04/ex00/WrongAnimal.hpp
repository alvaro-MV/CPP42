
#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal {

	protected:
		std::string type;
	
		public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal& animal);
			WrongAnimal& operator=(const WrongAnimal& animal);
			virtual ~WrongAnimal();

			virtual void makeSound(void) const;
			std::string getType(void) const;
};

#endif