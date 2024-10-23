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

int main()
{
	ClapTrap bob("Bob");
	ClapTrap lily("Lily");
	bob.attack("Lily");
	lily.takeDamage(0);
	lily.beRepaired(0);

	ScavTrap Anny("");
}