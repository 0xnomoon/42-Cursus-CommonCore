#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Constructor" << std::endl;
    type = "Animal";
}

Animal::~Animal() {
    std::cout << "Animal Destructor" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal Copy Constructor." << std::endl;
	type = other.type;
}

Animal & Animal::operator=(const Animal &other) {
	if (this != &other)
	{
		std::cout << "Animal Copy Assignment" << std::endl;
		type = other.type;
	}
	return *this;
}

void    Animal::makeSound() const {
    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType(void) const {
    return (type);
}