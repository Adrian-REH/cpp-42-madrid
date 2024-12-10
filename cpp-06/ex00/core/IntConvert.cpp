/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConvert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:23:47 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IntConvert.hpp"
#include <stdlib.h>
#include <climits>

void IntConvert::convertInt(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	double dbl = strtod(val, &endptr);

	int it = atoi(val);
	if (dbl <= INT_MAX && dbl >= INT_MIN)
		std::cout << "int:\t" << it <<std::endl;
	else
		std::cout << "int:\t" << "impossible" <<std::endl;
}
