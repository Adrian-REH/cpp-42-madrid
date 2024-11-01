/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:14 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 16:40:09 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "../repository/ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string			_name;
		static int			n_materias;
		static int			_n_drop_materias;
		AMateria	*_materias[4];
		AMateria	**_drop_materias;
	public:
		Character(std::string);
		~Character();
		std::string const & getName();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
#endif