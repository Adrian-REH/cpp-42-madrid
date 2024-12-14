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

void FloatConvert::convertFloat(std::string str) {

	char* endptr = NULL;
	const char* val = str.c_str();
	float flt = std::strtof(val, &endptr);

	if (std::isnan(flt))
		std::cout << "float:\t"<< "nanf" << std::endl;
	else if (std::isinf(flt))
		std::cout << ((flt < 0)? "float:\t-inff\n" : "float:\tinff\n");
	else
		std::cout  << std::scientific << "float:\t"<< std::setprecision(1) << flt << "f"<< std::endl;
}
