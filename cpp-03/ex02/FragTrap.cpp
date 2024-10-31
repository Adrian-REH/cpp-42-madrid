#include "FragTrap.hpp"
#include <iostream>
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

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
	<< "[Attack] FragTrap: " << YELLOW << _name<< RESET
	<< ", attacks: " << YELLOW << target << RESET 
	 << ", causing: "<< YELLOW << _attack_damage << RESET << " point of damage!" << std::endl;
	 _energy--;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "[Request] High fives" << std::endl;
}
