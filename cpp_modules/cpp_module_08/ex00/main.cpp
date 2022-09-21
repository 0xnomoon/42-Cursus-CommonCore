#include "easyfind.hpp"

int main()
{
    std::vector<int> vect;
    for (int i = 0; i < 40; i++)
        vect.push_back(i);
    try {
        std::cout << easyfind(vect, 2) << std::endl;
        std::cout << easyfind(vect, 30) << std::endl;
        std::cout << easyfind(vect, 897) << std::endl;
    }
    catch (std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}