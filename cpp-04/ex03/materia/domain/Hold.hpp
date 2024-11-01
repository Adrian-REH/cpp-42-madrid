/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hold.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:09:13 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Hold_HPP
#define Hold_HPP
#include "../repository/AMateria.hpp"

class Hold : public AMateria
{
	public:
		Hold();
		~Hold();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif