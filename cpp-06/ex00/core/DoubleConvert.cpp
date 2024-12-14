/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:55:51 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/14 17:39:17 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DoubleConvert.hpp"
#include <cmath>
#include <iomanip>

void DoubleConvert::convertDouble(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	double it = std::strtod(val, &endptr);

	if (std::isnan(it))
		std::cout << "double:\t"<< "nan" << std::endl;
	else if (std::isinf(it))
		std::cout << ((it < 0)? "double:\t-inf\n" : "double:\tinf\n");
	else
		std::cout  << std::scientific << "double:\t"<< std::setprecision(1) << it <<  std::endl;
}
