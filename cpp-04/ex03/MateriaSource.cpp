/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:34 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 19:55:37 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <string>
#include <iostream>
#include "stolower.hpp"

int MateriaSource::n_materias = 0;

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		_materias[i] = 0;
	}
}

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria * materia){
		if (n_materias >= 4)
		{
			std::cout << "Don't learning more material" << std::endl;
			return ;
		}
		materia->setIdx(n_materias);
		_materias[n_materias] = materia;
		n_materias++;
		std::cout << "Saved" << std::endl;
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
	return 0;
}
