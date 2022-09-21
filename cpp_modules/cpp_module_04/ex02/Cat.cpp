#include "Cat.hpp"

Cat::Cat() : brain(new Brain) {
    std::cout << "Cat Constructor" << std::endl;
    type = "Cat";
	brain->setIdeas();
}

Cat::~Cat() {
    std::cout << "Cat Destructor" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &other) {
	std::cout << "Dog Copy Constructor." << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat & Cat::operator=(const Cat &other) {
	if (this != &other)
	{
		std::cout << "Cat Copy Assignment" << std::endl;
		type = other.type;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow meeeoowww" << std::endl;
}

const Brain &Cat::getBrain() const {
	return *brain;
}