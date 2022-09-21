#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main() {
	FragTrap fragTrap("Ade");
	std::cout << fragTrap;

	fragTrap.attack("Joe");
	fragTrap.beRepaired(10);
	fragTrap.takeDamage(20);

	std::cout << fragTrap << std::endl;
	fragTrap.highFivesGuys();

	fragTrap.takeDamage(150);
	std::cout << fragTrap;
    return 0;
}