/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConvert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:23:39 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FloatConvert.hpp"
#include <cstdlib>
#include <cmath>

void FloatConvert::convertFloat(std::string str) {

	char* endptr = NULL;
	const char* val = str.c_str();
	double dbl = strtod(val, &endptr);
	float flt = strtof(val, &endptr);

	if (std::isnan(dbl))
		std::cout << "float:\t"<< "nanf" << std::endl;
	else
		std::cout << "float:\t"<< flt << std::endl;

}
