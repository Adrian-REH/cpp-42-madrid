/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:09 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:22:30 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

int Character::n_materias = 0;

Character::Character(std::string name) : _name(name) {}

Character::~Character() {
	for(int i = 0; i < 4 ; i++)
		_materias[i] = 0;
}
std::string const & Character::getName(){
	return (_name);
}

void Character::equip(AMateria* m)
{
		if ( !m || n_materias >= 4)
		{
			std::cout << "Don't equip more material" << std::endl;
			return ;
		}
		for (int i = 0; i < 4; i++)
		{
			if (!_materias[i])
			{
				_materias[i] = m;
				n_materias++;
				std::cout << "Equiped "<< std::endl;
				std::cout << m->getType() << std::endl;
				return ;
			}
		}
		m->setIdx(n_materias);
		_materias[n_materias] = m;
		n_materias++;
		std::cout << "Equiped"<< std::endl;
		return ;
}

void Character::unequip(int idx) {
	if (idx > n_materias || idx < 0)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i]->getIdx() == idx)
		{
			n_materias--;
			std::cout << "Unequiped "<<_materias[i]->getType() << std::endl;
			_materias[i] = 0;
			return ;
		}
	}
}
void Character::use(int idx, ICharacter &target){
	if (idx > n_materias || idx < 0)
		return ;
	if (_materias[idx])
	{
		std::cout << _name;
		_materias[idx]->use(target);}
}
