#include "Dog.hpp"

Dog::Dog() : brain(new Brain) {
    std::cout << "Dog Constructor" << std::endl;
    type = "Dog";
	brain->setIdeas();
}

Dog::~Dog() {
    std::cout << "Dog Destructor" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog Copy Constructor." << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog & Dog::operator=(const Dog &other) {
	if (this != &other)
	{
		std::cout << "Dog Copy Assignment" << std::endl;
		type = other.type;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "Doggo Doggo ouaf ouaf" << std::endl;
}

const Brain &Dog::getBrain() const {
	return *brain;
}
