#include "Conv.hpp"
#include "Display.hpp"

Conv::Conv(const std::string &in) : _in(in) {}

Conv::~Conv() {}

bool    Conv::Check() {
    if (isZ()) {
        Display("Non displayable", "0", "0.0f", "0.0");
        return (true);
    }
    if (_in == "nan" || _in == "nanf") {
        Display("impossible", "impossible", "nanf", "nan");
        return true;
    } else if (_in == "-inf" || _in == "-inff") {
        Display("impossible", "impossible", "-inff", "-infs");
        return true;
    } else if (_in == "+inf" || _in == "+inff") {
        Display("impossible", "impossible", "+inff", "+inf");
        return true;
    }
    for (size_t i = 0; i < _in.size(); ++i) {
        if (_in[0] == '-' || _in[0] == '+') continue;
        if (_in[i] != '.' && !isdigit(_in[i]) && _in[i] != 'f')
            exitError("conversion is impossible.", EXIT_FAILURE);
    }
    try {
        long long ll = atof(_in.c_str());
        if (ll > std::numeric_limits<int64_t>::max() || ll < std::numeric_limits<int64_t>::min())
            exitError("conversion is impossible.", EXIT_FAILURE);
    } catch (std::exception &e) {
        std::cout << "conversion is impossible." << std::endl;
    }
    return false;

}

bool    Conv::isZ() {
    for (size_t y = 0; y < _in.size(); ++y) {
        if (y == 0 && (_in[y] == '-' || _in[y] == '+'))
            continue;
        if (_in[y] != '0' && _in[y] != '.')
            return false;
    }
    return true;
}