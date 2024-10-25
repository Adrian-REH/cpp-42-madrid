/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:59:51 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 16:55:20 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club("Manticore lance");
		HumanA bob("Bob", club);
		
		bob.attack();
		club.setType("Silver heart lance");
		bob.attack();
	}
	{
		Weapon *club = new Weapon("Aileen Bow");
		HumanB lily("Lily");

		lily.setWeapon(club);
		lily.attack();
		club->setType("Sylph Wind Bow");
		lily.attack();
		delete club;
	}
}