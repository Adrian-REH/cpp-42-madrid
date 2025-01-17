/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:40 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/18 14:06:36 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "../repository/IMateriaSource.hpp"
#include "../../materia/repository/AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int			_n_materias;
		int			_n_drop_materias;
		AMateria	*_materias[4];
		AMateria	**_drop_materias;
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria*);
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		AMateria* createMateria(std::string const & type);
};

#endif