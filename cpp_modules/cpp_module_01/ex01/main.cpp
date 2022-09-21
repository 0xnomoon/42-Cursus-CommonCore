#include "Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(5, "hhhh");
	if (zombie == NULL)
		return (0);
	for (int i = 0; i < 5; i++)
		zombie[i].Announce();
	delete [] zombie;
}
