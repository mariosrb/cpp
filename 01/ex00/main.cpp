#include "Zombie.hpp"

int main (void)
{
	Zombie*	persistantZombie = newZombie("Bob");
	persistantZombie->announce();
	delete persistantZombie;

	randomChump("Jim");
	return (0);
}
