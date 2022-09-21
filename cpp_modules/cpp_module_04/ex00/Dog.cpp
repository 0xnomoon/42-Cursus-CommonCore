#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog Constructor" << std::endl;
    type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog Copy Constructor." << std::endl;
	type = other.type;
}

Dog & Dog::operator=(const Dog &other) {
	if (this != &other)
	{
		std::cout << "Dog Copy Assignment" << std::endl;
		type = other.type;
	}
	return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "Doggo Doggo ouaf ouaf" << std::endl;
}