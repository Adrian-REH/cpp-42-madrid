/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electric.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:11:25 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELECTRIC_HPP
#define ELECTRIC_HPP
#include "../repository/AMateria.hpp"

class Electric : public AMateria
{
	public:
		Electric();
		~Electric();
		Electric(const Electric&);
		Electric& operator=(const Electric&);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif