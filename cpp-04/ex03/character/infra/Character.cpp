/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:09 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 21:51:03 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "../../utils/realloc.cpp"
#include "../../materia/repository/AMateria.hpp"
#include <iostream>
Character::Character(): _name(""), n_materias(0), _n_drop_materias(0) {
	std::cout << "[Created] Character:" << _name << std::endl;

}
Character::Character(std::string name) : _name(name), n_materias(0), _n_drop_materias(0)  {
	std::cout << "[Created] Character: " << _name << std::endl;
}

Character::~Character() {
	std::cout << "[Destroyed] Character: " << _name << std::endl;
	for(int i = 0; i < n_materias; i++)
		delete  _materias[i];
	if (_n_drop_materias != 0) {
		std::cout << std::endl << "[Destroyed] Drop Character: "<< _name<< std::endl;
		for(int i = 0; i < _n_drop_materias; i++)
			delete _drop_materias[i];
	}
	std::cout << std::endl;
}

std::string const & Character::getName() {
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	if ( n_materias >= 4)
	{
		std::cout << "[Droped] Don't equip more material: " << m->getType()<< std::endl;
		_drop_materias = realloc_materia<AMateria>(_drop_materias, _n_drop_materias);
		_drop_materias[_n_drop_materias] = m;
		_n_drop_materias++;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			n_materias++;
			std::cout << "[Equiped] Material: "<< m->getType()<< std::endl;
			return ;
		}
	}
	m->setIdx(n_materias);
	_materias[n_materias] = m;
	n_materias++;
	std::cout << "[Equiped] Material: "<< m->getType()<< std::endl;
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
			std::cout << "[Droped] Unequip material: "<<_materias[i]->getType() << std::endl;
			_drop_materias = realloc_materia<AMateria>(_drop_materias, _n_drop_materias);
			_drop_materias[_n_drop_materias] = _materias[i];
			_n_drop_materias++;
			_materias[i] = 0;
			return ;
		}
	}
}

void Character::use(int idx, ICharacter &target){
	if (idx > n_materias || idx < 0)
	{
		std::cout << "[NotUse] Don't exist this material: " << idx<< std::endl;
		return ;
	}
	if (_materias[idx])
	{
		std::cout << _name;
		_materias[idx]->use(target);
		return ;
	}
	std::cout << "[NotFound] The character " << _name <<" has no further substance.: " << idx << std::endl;

}

Character::Character(const Character& character) {
	std::cout << "[Copy] Character" << std::endl;
	*this = character;
}

Character& Character::operator=(const Character& character){
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &character){
		this->n_materias = character.n_materias;
		this->_name = character._name;
		for (int i = 0; i < character.n_materias ; i++){
			this->_materias[i] = character._materias[i]->clone();
		}
		this->_n_drop_materias = 0;
		this->_drop_materias = NULL;
	}
	return *this;
}
