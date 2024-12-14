/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConvert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:41:20 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 20:22:34 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERT_HPP
#define CHARCONVERT_HPP
#include <string>
#include <iostream>
#include <limits>
#include <stdlib.h>

class CharConvert {
	private:
		CharConvert();
	public:
		static void convertChar(std::string);
};

#endif