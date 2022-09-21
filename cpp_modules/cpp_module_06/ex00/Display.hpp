#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include <iostream>
#include <cmath>

class Display {
    public:
        Display(const std::string& dChar, const std::string& dInt, const std::string& dFloat, const std::string& dDouble);
        Display(char dChar, int dInt, float dFloat, double dDouble, bool aff, bool possibleConv);
};

#endif