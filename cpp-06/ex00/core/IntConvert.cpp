/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConvert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/14 16:55:51 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IntConvert.hpp"
#include <stdlib.h>
#include <climits>

IntConvert::IntConvert() {
	std::cout << "[Build] Int convert" << std::endl;
}

IntConvert::~IntConvert() {
	std::cout << "[Destroyed] Int convert" << std::endl;
}

IntConvert::IntConvert(IntConvert const &src) {
	std::cout << "[Copy] Int convert" << std::endl;
	*this = src;
}

IntConvert & IntConvert::operator=(IntConvert const &src) {
	std::cout << "[Assignament] Int convert" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

int isdisplayablei(char it) {
	return (it >= 32 && it <= 126);
}

void IntConvert::convertInt(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	double dbl = std::strtod(val, &endptr);
	int it = atoi(val);
	if (str.length() < 2 && isdisplayablei(static_cast<char>(val[0])))
		it = static_cast<int>(val[0]);
	
	if (dbl <= INT_MAX && dbl >= INT_MIN)
		std::cout << "int:\t" << it <<std::endl;
	else
		std::cout << "int:\t" << "impossible" <<std::endl;
}
