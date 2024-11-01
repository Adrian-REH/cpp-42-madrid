/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 13:17:59 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../domain/Fire.hpp"
#include <iostream>

Fire::Fire() : AMateria("fire") {
	std::cout << "[Created] Material fire" << std::endl;

}
Fire::~Fire() {
	std::cout << " Cure " << std::endl;}

AMateria* Fire::clone() const {
	AMateria *nFire = new Fire();
	return nFire;
}

void Fire::use(ICharacter& target) {
	std::cout << " Fired " << target.getName() << "’s wounds" <<  std::endl;
}
