#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal* array[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			array[i] = new Dog;
		else
			array[i] = new Cat;
	}
	for (int i = 0; i < 10; i++)
		delete array[i];

	Cat* lil = new Cat;
	Cat* lilcopy = new Cat(*lil);
	std::cout << "Cat Brain ideas: " <<lil->getBrain() << std::endl;
	delete lil;
	std::cout << "Cat Copy Brain ideas: "<< lilcopy->getBrain() << std::endl;
	delete lilcopy;

	Dog* doggo = new Dog;
	Dog* doggo1 = new Dog(*doggo);
	std::cout << "Dog Brain ideas: "<< doggo->getBrain() << std::endl;
	delete doggo;
	std::cout << "Dog Copy Brain ideas: "<< doggo1->getBrain() << std::endl;
	delete doggo1;
}