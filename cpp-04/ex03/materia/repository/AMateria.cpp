/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:12:22 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include "../../utils/stolower.hpp"


AMateria::AMateria(std::string const &type){
	stolower(type);
	_type = type;
}
AMateria::~AMateria() {
	std::cout << "[Destroyed] AMateria " << std::endl;
}

std::string const & AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

void AMateria::setIdx(int idx) {
	_idx = idx;
}

int AMateria::getIdx() const {
	return _idx;
}

bool AMateria::isEmpty(){
	return (_type.empty());
}