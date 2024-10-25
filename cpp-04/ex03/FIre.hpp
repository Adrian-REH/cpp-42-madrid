/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIre.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:26:59 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
#define FIRE_HPP
#include "AMateria.hpp"

class Fire : public AMateria
{
	public:
		Fire();
		~Fire();
		AMateria* clone() const;
};

#endif