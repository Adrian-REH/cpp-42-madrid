
#include "Zombie.hpp"

void Zombie::announce(){
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::~Zombie() {
    std::cout << "Zombie " << " destruido." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {}
