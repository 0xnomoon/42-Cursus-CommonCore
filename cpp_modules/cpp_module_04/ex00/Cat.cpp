#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat Constructor" << std::endl;
    type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat Copy Constructor." << std::endl;
	type = other.type;
}

Cat & Cat::operator=(const Cat &other) {
	if (this != &other)
	{
		std::cout << "Cat Copy Assignment" << std::endl;
		type = other.type;
	}
	return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow meeeoowww" << std::endl;
}