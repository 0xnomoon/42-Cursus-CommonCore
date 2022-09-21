#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed();
    Fixed(const int x);
    Fixed(const Fixed &other);
    Fixed(float const f);
    ~Fixed();
    Fixed & operator=(const Fixed &other);
    int getRawBits() const;
    void setRawBits(int raw);
    float toFloat() const;
    int toInt() const;
private:
    int fixedInt;
    static const int BITS = 8;
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);

#endif
