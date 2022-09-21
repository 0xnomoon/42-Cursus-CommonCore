#include "Fixed.hpp"

Fixed::Fixed() : fixInt(0) {
    std::cout << "Constructor called." << std::endl;
    fixInt = 0;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const Fixed &o) {
    *this = o;
}

Fixed &Fixed::operator=(const Fixed &o) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &o)
		this->fixInt = o.getRawBits();
	return *this;
}

int    Fixed::getRawBits(void) const {
    return (fixInt);
}

void    Fixed::setRawBits(int i) {
    fixInt = i;
}

