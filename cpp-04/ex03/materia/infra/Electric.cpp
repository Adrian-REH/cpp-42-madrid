/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electric.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:09:53 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../domain/Electric.hpp"
#include <iostream>

Electric::Electric() : AMateria("electric") {
	std::cout << "[Created] Material Electric" << std::endl;
}

Electric::~Electric() {
	std::cout << "[Destroyed] Electric - ";
}

AMateria* Electric::clone() const {
	AMateria *nElec = new Electric();
	return nElec;
}

void Electric::use(ICharacter& target) {
	std::cout << " Electrocuted " << target.getName() << "’s wounds"<<  std::endl;
}