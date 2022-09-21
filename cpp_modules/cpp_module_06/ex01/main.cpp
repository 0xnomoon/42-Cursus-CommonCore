#include "Uint.hpp"

Data::Data(int i, char c, float f, double d) : _i(i), _c(c), _f(f), _d(d) {};

//reinterpret_cast Converts between types by reinterpreting the underlying bit pattern. 
uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr);}
Data* deserialize(uintptr_t raw) {return reinterpret_cast<Data *>(raw);}

int main() {
    Data *data = new Data(50, '2', 50.0f, 50.0);
    uintptr_t r = serialize(data);
    std::cout << "int: " << data->_i << std::endl << "char: " << data->_c << std::endl << "float: " << data->_f << std::endl << "double: " << data->_d << std::endl;
    Data *o = deserialize(r);
    std::cout << "int: " << o->_i << std::endl << "char: " << o->_c << std::endl << "float: " << o->_f << std::endl << "double: " << o->_d << std::endl;
}