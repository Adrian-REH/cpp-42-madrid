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
    std::cout << YELLOW << "[Init]" << RESET << " FragTrap "<< YELLOW << "[Created]" << RESET << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << RED <<"[Destroy]"<< RESET << " FragTrap: " << _name << RED << " [Destructed]"<< RESET << std::endl;
}

void	FragTrap::attack(const std::string& target) {
    std::cout 
        << BLUE << "[Attack] " << RESET 
		<<"FragTrap: " << _name 
        << ", attacks: " << target 
        << ", causing: " << _attack_damage << " point of damage!" << std::endl;
	 _energy--;
}

void	FragTrap::highFivesGuys(void) {
    std::cout << GREEN << "[Mode]"<< RESET <<" Change to mode Gatekeeper" << std::endl;
}
