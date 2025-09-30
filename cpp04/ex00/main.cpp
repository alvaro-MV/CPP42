#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	// const Animal* j = new Dog();
// 	// const Animal* i = new Cat();
// 	const WrongAnimal* i = new WrongCat();
// 	// std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	// j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete i;
// 	// delete j;

// 	return 0;
// }

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	return 0;
}