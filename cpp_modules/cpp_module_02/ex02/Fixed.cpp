#include "Fixed.hpp"

#define FIXED_P (1 << 8) //"00000000 00000001" -> "00000001 00000000"

Fixed::Fixed() : fixedInt(0) {}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return fixedInt;
}

void Fixed::setRawBits(int const raw) {
	this->fixedInt = raw;
}

Fixed::Fixed(Fixed const &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if(this != &other)
		this->fixedInt = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int x) {
	fixedInt = (x << BITS);
}

Fixed::Fixed(const float f) {
	fixedInt = std::roundf(f * FIXED_P);
}

float Fixed::toFloat() const {
	return (float) fixedInt / FIXED_P;
}

int Fixed::toInt() const {
	return fixedInt >> BITS;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

bool Fixed::operator>(Fixed const &rhs) const {
	return this->fixedInt > rhs.fixedInt;
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->fixedInt < rhs.fixedInt;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->getRawBits() <= rhs.getRawBits();;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->getRawBits() == rhs.getRawBits();;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return !(*this == rhs);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if(rhs.toInt() > 0)
		return Fixed(this->toFloat() / rhs.toFloat());
	else
		throw std::runtime_error("Cannot divide by zero");
}

Fixed Fixed::operator++(int) {
	Fixed fixed(*this);
	++fixedInt;
	return fixed;
}

Fixed &Fixed::operator++() {
	this->fixedInt++;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed fixed(*this);
	--fixedInt;
	return fixed;
}

Fixed &Fixed::operator--() {
	this->fixedInt--;
	return *this;
}

Fixed &Fixed::mini(Fixed &fixed1, Fixed &fixed2) {
	if(fixed1.fixedInt < fixed2.fixedInt)
		return fixed1;
	else
		return fixed2;
}

const Fixed &Fixed::mini(const Fixed &fixed1, const Fixed &fixed2) {
	if(fixed1.fixedInt < fixed2.fixedInt)
		return fixed1;
	else
		return fixed2;
}

Fixed &Fixed::maxi(Fixed &fixed1, Fixed &fixed2) {
	if(fixed1.fixedInt > fixed2.fixedInt)
		return fixed1;
	else
		return fixed2;
}

const Fixed &Fixed::maxi(const Fixed &fixed1, const Fixed &fixed2) {
	if(fixed1.fixedInt > fixed2.fixedInt)
		return fixed1;
	else
		return fixed2;
}


std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed) {
	ostream << fixed.toFloat();
	return ostream;
}
