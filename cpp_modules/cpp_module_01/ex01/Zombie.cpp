#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name): _name(name) {}

void Zombie::Announce(void)
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << _name << " died." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}