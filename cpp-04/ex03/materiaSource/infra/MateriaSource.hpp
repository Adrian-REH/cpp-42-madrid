/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:40 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 13:07:39 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "../repository/IMateriaSource.hpp"
#include "../../materia/repository/AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static int	n_materias;
		AMateria	*_materias[4];
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif