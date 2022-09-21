#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat Constructor" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << "WrongCat Copy Constructor." << std::endl;
	type = other.type;
}

WrongCat & WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
	{
		std::cout << "WrongCat Copy Assignment" << std::endl;
		type = other.type;
	}
	return *this;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "WrongCat sound Meow meeeoowww" << std::endl;
}