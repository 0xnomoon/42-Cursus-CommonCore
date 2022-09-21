#ifndef CONV_HPP
#define CONV_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <limits>
#include "Display.hpp"

class Conv {
    public:
        Conv(const std::string &in);
        ~Conv();
        void    Parse();
        bool    Check();
        bool    isInt();
        bool    isDouble();
        bool    isFloat();
        bool    isZ();
    private:
        std::string _in;
};

int exitError(std::string const &err, int code);

#endif