/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:57:43 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:57:44 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newZombie.cpp"
#include "randomChump.cpp"
#include "Zombie.hpp"

int main()
{
	Zombie zom = Zombie("Foo");
	zom.announce();
	zom.~Zombie();
	Zombie *anna = newZombie("Anna");
	anna->announce();
	randomChump("Federico");
}