#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name)
: ClapTrap(name, 100, 100, 30)
{
	std::cout << "[Init] FragTrap [Created]" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[Destroy] FragTrap " << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	std::cout 
	<< "[Attack] FragTrap: " << _name
	<< ", attacks: " << target
	 << ", causing: "<< _attack_damage << " point of damage!" << std::endl;
	 _energy--;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "[Request] High fives" << std::endl;
}
