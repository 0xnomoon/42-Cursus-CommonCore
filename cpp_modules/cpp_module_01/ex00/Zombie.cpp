#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
}

void Zombie::Announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " died." << std::endl;
}
