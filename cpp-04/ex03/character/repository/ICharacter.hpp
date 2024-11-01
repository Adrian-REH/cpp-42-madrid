/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:20 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 13:04:40 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include <string>
#include "../../materia/repository/AMateria.hpp"
class AMateria;
/**
 * Pure Virtual class that equal to interface
 */
class ICharacter
{
	public:
		virtual ~ICharacter(){}
		virtual std::string const & getName() = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif