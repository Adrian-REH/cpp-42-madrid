/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electric.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:30:42 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Electric.hpp"
#include <iostream>

Electric::Electric() : AMateria("electric") {
	std::cout << "Create Material Electric" << std::endl;
}

Electric::~Electric() {}

AMateria* Electric::clone() const {
	AMateria *nElec = new Electric();
	return nElec;
}
