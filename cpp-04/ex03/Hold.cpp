/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hold.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:31:42 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Hold.hpp"
#include <iostream>

Hold::Hold() : AMateria("hold") {
	std::cout << "Create Material Hold" << std::endl;
}

Hold::~Hold() {}

AMateria* Hold::clone() const {
	AMateria *nHold = new Hold();
	return nHold;
}
