#include "FragTrap.hpp"
#include <iostream>
#define GREEN  "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE   "\033[36m"
#define RESET  "\033[0m"
#define RED    "\033[31m"
FragTrap::FragTrap(std::string name)
: ClapTrap(name, 100, 100, 30)
{
    std::cout  << "[Init]"  << " FragTrap " << "[Created]"  << std::endl;
}

FragTrap::~FragTrap() {
    std::cout  <<"[Destroy]" << " FragTrap: " << GREEN << _name << RESET  << " [Destructed]" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
    std::cout 
         << "[Attack] "  
		<<"FragTrap: " << GREEN << _name  << RESET
        << ", attacks: " << GREEN << target << RESET 
        << ", causing: " << GREEN << _attack_damage << RESET << " point of damage!" << std::endl;
	 _energy--;
}

void	FragTrap::highFivesGuys(void) {
    std::cout  << "[Mode]" <<" Change to mode Gatekeeper" << std::endl;
}
