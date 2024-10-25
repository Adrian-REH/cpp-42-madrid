/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electric.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:30:42 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELECTRIC_HPP
#define ELECTRIC_HPP
#include "AMateria.hpp"

class Electric : public AMateria
{
	public:
		Electric();
		~Electric();
		AMateria* clone() const;
};

#endif