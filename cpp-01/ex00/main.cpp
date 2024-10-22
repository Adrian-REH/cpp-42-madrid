
#include "newZombie.cpp"
#include "randomChump.cpp"
#include "Zombie.hpp"

int main()
{
	Zombie zom = Zombie("Foo");
	zom.announce();
	zom.~Zombie();
	Zombie *anna = newZombie("Anna");
	anna->announce();
	randomChump("Federico");
}