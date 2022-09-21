#include "Fixed.hpp"

#define FIXED_P (1 << 8) //"00000000 00000001" -> "00000001 00000000"

Fixed::Fixed() : fixedInt(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) {
	std::cout << "Int constructor called" << std::endl;
	fixedInt = (x << BITS);
}

Fixed::Fixed(const float f)  {
	std::cout << "Float constructor called" << std::endl;
	fixedInt = std::roundf(f * FIXED_P);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return fixedInt;
}

void Fixed::setRawBits(int const raw) {
    fixedInt = raw;
}

Fixed::Fixed(Fixed const &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        this->fixedInt = other.getRawBits();
    return *this;
}

float Fixed::toFloat() const {
    return (float )fixedInt / FIXED_P;
}

int Fixed::toInt() const {
    return fixedInt >> BITS;
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed) {
    ostream << fixed.toFloat();
    return ostream;
}
