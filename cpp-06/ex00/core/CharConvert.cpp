/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConvert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:02 by adherrer          #+#    #+#             */
/*   Updated: 2025/01/14 14:53:41 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CharConvert.hpp"

CharConvert::CharConvert() {
	std::cout << "[Build] Char convert" << std::endl;
}

CharConvert::~CharConvert() {
	std::cout << "[Destroyed] Char convert" << std::endl;
}

CharConvert::CharConvert(CharConvert const &src) {
	std::cout << "[Copy] Char convert" << std::endl;
	*this = src;
}

CharConvert & CharConvert::operator=(CharConvert const &src) {
	std::cout << "[Assignament] Char convert" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

int isdisplayablec(double it) {
	return (it >= 32 && it <= 126);
}

void CharConvert::convertChar(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	double it = std::strtod(val, &endptr);
	if (str.length() == 1 && !isdigit(static_cast<double>(val[0])) && isdisplayablec(val[0]))
		it = static_cast<char>(val[0]);

	if (isdisplayablec(it))
		std::cout << "char:\t\'"<< static_cast<char>(it) <<"\'" << std::endl;
	else if (str.length() > 3)
		std::cout << "char:\t"<< "impossible" << std::endl;
	else
		std::cout << "char:\t"<< "Non displayable" << std::endl;
}
