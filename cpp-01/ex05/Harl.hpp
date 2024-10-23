/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:00:41 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:00:41 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl{ 
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		static void (Harl::*_k[4])(void);
		static std::string _states[4];
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif