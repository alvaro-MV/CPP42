#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *zoo[4];
	for (int i = 0; i < 4; i++)
	{
		if (i > 1)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
	}

	std::cout << std::endl;
	zoo[0]->makeSound();
	zoo[0]->setIdea(5, "Listeza");
	zoo[0]->getIdea(5);
	zoo[0]->getIdea(-5);

	std::cout << std::endl;
	zoo[2]->makeSound();
	zoo[2]->getIdea(5);
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete zoo[i];
	}
	return 0;
}