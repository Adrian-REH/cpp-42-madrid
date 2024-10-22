
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombs = new Zombie[N];
	for (int i = 0 ; i < N ; ++i)
		zombs[i] = Zombie(name);
	return zombs;
}