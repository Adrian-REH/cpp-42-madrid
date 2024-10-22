#include "HumanB.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

HumanB::HumanB(std::string name, Weapon& weapon) : _weapon(weapon), _name(name)
{

}

HumanB::~HumanB()
{
	std::cout << _name << RED << " Dead" << RESET << std::endl;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << YELLOW << _weapon.getType() << RESET << std::endl; 
}