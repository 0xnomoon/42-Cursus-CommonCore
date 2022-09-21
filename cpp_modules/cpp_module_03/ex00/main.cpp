#include "ClapTrap.hpp"

int    main() {
    ClapTrap clapTrap("Joe");
    std::cout << clapTrap << std::endl;
    clapTrap.attack("hhhh");
    clapTrap.beRepaired(28);
    clapTrap.takeDamage(12);
    std::cout << clapTrap << std::endl;
    std::cout << "ClapTrap Using Copy Constructor" << std::endl;
    ClapTrap clapTrap1(clapTrap);
    std::cout << clapTrap1 << std::endl;
    std::cout << "ClapTrap Using Assignement Operator" << std::endl;
    ClapTrap clapTrap2("Ade");
    clapTrap1 = clapTrap2;
    std::cout << clapTrap1 << std::endl;
    return (0);
}