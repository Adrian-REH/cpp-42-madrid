/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:16:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 13:41:00 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "iostream"
#define GREEN  "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE   "\033[36m"
#define RESET  "\033[0m"
#define RED    "\033[31m"

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << YELLOW << "[Init]" << RESET << " ScavTrap "<< YELLOW << "[Created]" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << RED <<"[Destroy]"<< RESET << " ScavTrap: " << _name << RED << " [Destructed]"<< RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout 
        << BLUE << "[Attack] " << RESET << "ScavTrap: " << _name 
        << ", attacks: " << target 
        << ", causing: " << _attack_damage << " point of damage!" << RESET << std::endl;
    _energy--;
}

void ScavTrap::guardGate() {
    std::cout << GREEN << "[Mode] Change to mode Gatekeeper" << RESET << std::endl;
}
