/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConvert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:25:53 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CharConvert.hpp"

int isdisplayable(double it) {
	return (it >= 32 && it <= 126);
}

void CharConvert::convertChar(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	double it = strtod(val, &endptr);

	if (isdisplayable(it))
		std::cout << "char:\t"<< static_cast<char>(it) << std::endl;
	else if (str.length() > 1)
		std::cout << "char:\t"<< "impossible" << std::endl;
	else
		std::cout << "char:\t"<< "Non displayable" << std::endl;
}
