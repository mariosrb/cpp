#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <ctype.h>

class Zombie {

private:
	std::string name;

public:
	Zombie();
	Zombie(std::string zombieName);
	~Zombie();
	void announce(void);
	void setName(std::string zombieName);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);


#endif
