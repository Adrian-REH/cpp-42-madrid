/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:19:35 by adherrer         ###   ########.fr       */
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
	if (_type.compare("ice"))
		 std::cout << "shoots an ice bolt at " << target.getName() <<  std::endl;
	else if (_type.compare("cure"))
		 std::cout << " heals" << target.getName() << "’s wounds";
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