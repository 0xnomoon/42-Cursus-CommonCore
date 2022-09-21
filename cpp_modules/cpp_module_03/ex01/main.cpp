#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	ClapTrap clapTrap("Joe");
	std::cout << clapTrap;
	std::cout << std::endl << "Making a ScavTrap" << std::endl;
	ScavTrap scavTrap("Hhhh");
	std::cout << scavTrap;
	scavTrap.attack("Ade");
	scavTrap.beRepaired(20);
	scavTrap.takeDamage(8);
	std::cout << scavTrap << std::endl;
	scavTrap.guardGate();
	scavTrap.takeDamage(200);
	std::cout << scavTrap;
	std::cout << std::endl << "ScavTrap from another ScavTrap" << std::endl;
	ScavTrap scavTrapCopy(scavTrap);
	std::cout << scavTrapCopy;
	std::cout << std::endl << "Make reference to ScavTrap" << std::endl;
	ClapTrap &clapTrapR = scavTrap;
	clapTrapR.beRepaired(10);
    return 0;
}