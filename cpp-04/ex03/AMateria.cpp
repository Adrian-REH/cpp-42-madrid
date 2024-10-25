/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 13:59:48 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type){
	_type = type;
}
std::string const & AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Non define type"<< std::endl;
}
