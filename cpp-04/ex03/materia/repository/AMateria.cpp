/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 17:18:49 by adherrer         ###   ########.fr       */
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
	std::cout << "[Destroy] Abstract";
}

std::string const & AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	if (!_type.compare("ice"))
		 std::cout << "shoots an ice bolt at " << target.getName() <<  std::endl;
	else if (!_type.compare("cure"))
		 std::cout << " heals " << target.getName() << "’s wounds" <<  std::endl;
	else if (!_type.compare("hold"))
		 std::cout << " Defense increase " << target.getName() << "’s wounds" <<  std::endl;
	else if (!_type.compare("electric"))
		 std::cout << " Electrocuted " << target.getName() << "’s wounds"<<  std::endl;
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