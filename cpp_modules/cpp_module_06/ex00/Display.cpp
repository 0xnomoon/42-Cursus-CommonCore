#include "Display.hpp"

Display::Display(const std::string& dChar, const std::string& dInt, const std::string& dFloat, const std::string& dDouble){
    std::cout << "char: " << dChar << std::endl << "int: " << dInt << std::endl << "float: " << dFloat << std::endl << "double: " << dDouble << std::endl;
}

Display::Display(char dChar, int dInt, float dFloat, double dDouble, bool aff, bool possibleConv) {
    if ((int)dChar > 32 && (int)dChar < 128 && !possibleConv)
        std::cout << "char: '" << dChar << "'" << std::endl;
    else if (!possibleConv)
        std::cout << "char: Non displayable." << std::endl;
    if (!possibleConv)
        std::cout << "int: " << dInt << std::endl;
    if (aff)
        std::cout << "float: " << dFloat << ".0f" << std::endl << "double: " << dDouble << ".0" << std::endl;
    else
        std::cout << "float: " << dFloat << "f" << std::endl << "double: " << dDouble << std::endl;
}