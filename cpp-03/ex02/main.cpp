/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:07:56 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 13:29:14 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
int main()
{
	ClapTrap bob("Bob");
	ClapTrap lily("Lily");
	bob.attack("Lily");
	lily.takeDamage(0);
	lily.beRepaired(0);

	std::cout << std::endl;
	ScavTrap anny("Anny");

	anny.attack("Lily");
	bob.takeDamage(20);
	bob.attack("Anny");
	anny.takeDamage(20);

	std::cout << std::endl;
	FragTrap enry("Enry");

	enry.highFivesGuys();
	enry.attack("Lily");
	lily.takeDamage(30);
	enry.attack("Bob");
	bob.takeDamage(30);
	std::cout << std::endl;
}