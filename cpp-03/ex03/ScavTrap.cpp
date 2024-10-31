/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:16:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/30 20:41:37 by adherrer         ###   ########.fr       */
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
    std::cout  << "[Init]"  << " ScavTrap " << "[Created]"  << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout  <<"[Destroy]" << " ScavTrap: " << YELLOW << _name << RESET  << " [Destructed]" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout 
         << "[Attack] "  << "ScavTrap: " <<YELLOW << _name << RESET
        << ", attacks: " << YELLOW  << target << RESET
        << ", causing: " << YELLOW << _attack_damage << RESET << " point of damage!"  << std::endl;
    _energy--;
}

void ScavTrap::guardGate() {
    std::cout  << "[Mode] Change to mode Gatekeeper"  << std::endl;
}
