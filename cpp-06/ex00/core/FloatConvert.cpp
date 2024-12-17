/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConvert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/14 17:39:17 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FloatConvert.hpp"
#include <cstdlib>
#include <cmath>
#include <iomanip>

FloatConvert::FloatConvert() {
	std::cout << "[Build] Float convert" << std::endl;
}

FloatConvert::~FloatConvert() {
	std::cout << "[Destroyed] Float convert" << std::endl;
}

FloatConvert::FloatConvert(FloatConvert const &src) {
	std::cout << "[Copy] Float convert" << std::endl;
	*this = src;
}

FloatConvert & FloatConvert::operator=(FloatConvert const &src) {
	std::cout << "[Assignament] Float convert" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

int isdisplayablef(char it) {
	return (it >= 32 && it <= 126);
}

void FloatConvert::convertFloat(std::string str) {

	char* endptr = NULL;
	const char* val = str.c_str();
	float flt = std::strtof(val, &endptr);
	if (str.length() < 2 && isdisplayablef(val[0]))
		flt = static_cast<float>(val[0]);

	if (std::isnan(static_cast<float>(flt)))
		std::cout << "float:\t"<< "nanf" << std::endl;
	else if (std::isinf(static_cast<float>(flt)))
		std::cout << ((static_cast<float>(flt) < 0)? "float:\t-inff\n" : "float:\tinff\n");
	else
		std::cout  << std::scientific << "float:\t"<< std::setprecision(1) << static_cast<float>(flt) << "f"<< std::endl;
}
