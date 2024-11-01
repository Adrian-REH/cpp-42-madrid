/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hold.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:09:09 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../domain/Hold.hpp"
#include <iostream>

Hold::Hold() : AMateria("hold") {
	std::cout << "[Created] Material Hold" << std::endl;
}

Hold::~Hold() {
	std::cout << "[Destroyed] Hold - ";
}

AMateria* Hold::clone() const {
	AMateria *nHold = new Hold();
	return nHold;
}

void Hold::use(ICharacter& target) {
	std::cout << " Defense increase " << target.getName() << "’s wounds" <<  std::endl;
}