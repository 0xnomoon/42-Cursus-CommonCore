#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal Constructor" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal Copy Constructor." << std::endl;
	type = other.type;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
	{
		std::cout << "WrongAnimal Copy Assignment" << std::endl;
		type = other.type;
	}
	return *this;
}

void    WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return (type);
}