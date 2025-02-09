/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:14 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 19:25:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "../repository/ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string			_name;
		int			n_materias;
		int			_n_drop_materias;
		AMateria	*_materias[4];
		AMateria	**_drop_materias;
	public:
		Character();
		Character(std::string);
		Character(const Character&);
		Character& operator=(const Character&);
		~Character();
		std::string const & getName();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
#endif