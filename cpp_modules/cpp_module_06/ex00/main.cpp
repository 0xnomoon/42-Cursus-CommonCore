#include "Conv.hpp"
#include "Display.hpp"
#include <limits.h>

int exitError(std::string const &err, int code) {
    std::cout << err << std::endl;
    exit(code);
}

bool    Same(double k, double l) {
    return fabs(k - l) < std::numeric_limits<double>::epsilon(); //fabs Compute absolute value
}

int main(int ac, char **av) {
    if (ac == 2) {
        int     i;
        float   f;
        double  d;
        char    c;
        std::string in(av[1]);
        Conv        conv(in);
        if (!conv.Check()) {
            try {
                f = atof(in.c_str()); // Interprets a floating point value in a string str
                i = atof(in.c_str()); //Convert string to integer
                d = static_cast<double>(f);
                c = static_cast<char>(i);
                if (i < 32 || i > 127)
                    c = 0;
                if (Same(f, i))
                    Display(c, i, f, d, true, false);
                else
                    Display(c, i, f, d, false, false);
            } catch (std::exception &except) {
                std::cout << "char: impossible." << std::endl << "int: impossible." << std::endl;
                d = (double)f;
                Display(-1, -1, f, d, false, true);
            }
        }
    } else
        std::cout << "Error: arguments." << std::endl;
}