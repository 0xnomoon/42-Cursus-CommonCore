#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
   public:
        Fixed();
        Fixed(const Fixed &o);
        ~Fixed();
        Fixed & operator=(const Fixed &o);
        int     getRawBits(void) const;
        void    setRawBits(int P);
    private:
        int fixInt;
        static const int BITS = 8;
};

#endif