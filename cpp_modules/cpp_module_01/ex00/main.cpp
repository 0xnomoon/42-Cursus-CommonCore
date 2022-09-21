#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;

	Zombie zombie1(std::string("jojo"));
	zombie1.Announce();
	zombie = newZombie("uer");
	zombie->Announce();
	randomChump("hhhh");
	delete zombie;
}
