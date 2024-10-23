/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:57:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:57:59 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(){
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::~Zombie() {
    std::cout << "Zombie " << " destruido." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {}
