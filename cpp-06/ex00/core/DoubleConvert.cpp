/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:55:51 by adherrer          #+#    #+#             */
/*   Updated: 2025/01/14 14:53:58 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DoubleConvert.hpp"
#include <cmath>
#include <iomanip>

int isdisplayabled(char it) {
	return (it >= 32 && it <= 126);
}

DoubleConvert::DoubleConvert() {
	std::cout << "[Build] Double convert" << std::endl;
}

DoubleConvert::~DoubleConvert() {
	std::cout << "[Destroyed] Double convert" << std::endl;
}

DoubleConvert::DoubleConvert(DoubleConvert const &src) {
	std::cout << "[Copy] Double convert" << std::endl;
	*this = src;
}

DoubleConvert & DoubleConvert::operator=(const DoubleConvert &src) {
	std::cout << "[Assignament] Double convert" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}


void DoubleConvert::convertDouble(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	double it = std::strtod(val, &endptr);
	if (str.length() < 2 && !isdigit(static_cast<char>(val[0])) && isdisplayabled(val[0]))
		it = static_cast<double>(val[0]);

	if (std::isnan(static_cast<double>(it)))
		std::cout << "double:\t"<< "nan" << std::endl;
	else if (std::isinf(static_cast<double>(it)))
		std::cout << ((static_cast<double>(it) < 0)? "double:\t-inf\n" : "double:\tinf\n");
	else
		std::cout  << std::scientific << "double:\t"<< std::setprecision(1) << static_cast<double>(it) <<  std::endl;
}
