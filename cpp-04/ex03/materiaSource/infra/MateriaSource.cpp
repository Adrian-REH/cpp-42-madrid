/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:34 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:06:29 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <string>
#include <iostream>
#include "../../utils/realloc.cpp"
#include "../../utils/stolower.hpp"


MateriaSource::MateriaSource() : _n_materias(0), _n_drop_materias(0) {
	std::cout << "[Created] MaterialSource" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "[Destroyed] MaterialSource" << std::endl;
	for(int i = 0; i < _n_materias; i++)
		delete  _materias[i];
	std::cout << std::endl;
	if (_n_drop_materias != 0){
		std::cout << "[Destroyed] Drop MaterialSource " << std::endl;
		for(int i = 0; i < _n_drop_materias; i++)
			delete _drop_materias[i];
	}
	std::cout << std::endl;
}

void MateriaSource::learnMateria(AMateria * materia){
	if (_n_materias >= 4)
	{
		std::cout << "[Droped] Don't equip more material: " << materia->getType() << std::endl;
		_drop_materias = realloc_materia<AMateria>(_drop_materias, _n_drop_materias);
		_drop_materias[_n_drop_materias] = materia;
		_n_drop_materias++;
		return ;
	}
	materia->setIdx(_n_materias);
	_materias[_n_materias] = materia;
	_n_materias++;
	std::cout << "[Saved] Saved in MateriaSource: "<<  materia->getType()  << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	stolower(type);
	for(int i = 0; i < 4; i++)
	{
		if (_materias[i] && !_materias[i]->isEmpty()  && !stolower(_materias[i]->getType()).compare(type))
		{
			return (_materias[i]->clone());}
	}
	std::cout << "[NotFound] Cannot create material: "<< type << std::endl;
	return 0;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource) {
	std::cout << "[Copy] MaterialSource" << std::endl;
	*this = materiaSource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource){
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &materiaSource){
		this->_n_materias = materiaSource._n_materias;
		for (int i = 0; i < materiaSource._n_materias ; i++){
			this->_materias[i] = materiaSource._materias[i]->clone();
		}
		this->_n_drop_materias = 0;
		this->_drop_materias = NULL;
	}
	return *this;
}
