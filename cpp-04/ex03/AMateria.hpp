/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:05 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 18:39:30 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		int _idx;
		std::string _type;
	public:
		AMateria(std::string const &type);
		std::string const &getType() const;
		int getIdx() const;
		void setIdx(int);
		bool isEmpty();

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif