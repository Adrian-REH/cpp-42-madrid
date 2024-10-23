
#include "DiamondTrap.hpp"
#include <iostream>
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE "\033[36m"
#define RESET "\033[0m"
#define RED "\033[31m"
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hit_point = FragTrap::_hit_point;
    _energy = ScavTrap::_energy;
    _attack_damage = FragTrap::_attack_damage;
    std::cout << YELLOW << "[Init]" << RESET
	<< "DiamondTrap " << _name << YELLOW <<" [Created]"<< RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED <<"[Destroy]"<< RESET << " DiamondTrap: " << _name << RED << " [Destructed]"<< RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << BLUE << "[Notify]"<< RESET <<" DiamondTrap: " << _name << " ClapTrap: " << ClapTrap::_name << std::endl;
}
