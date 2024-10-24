/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:00:11 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:00:11 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEEAPON_HPP
#define WEEAPON_HPP
#include <string>

class Weapon{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		std::string getType(void);
};

#endif