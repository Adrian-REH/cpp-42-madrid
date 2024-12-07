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

void FloatConvert::convertFloat(std::string str) {

	char* endptr = NULL;
	const char* val = str.c_str();
	float flt = strtof(val, &endptr);

	std::cout << "type\t│ lowest()\t│ min()\t\t│ max()\n"
				<< "float\t│ "
				<< std::numeric_limits<float>::lowest() << "\t│ "
				<< std::numeric_limits<float>::min() << "\t│ "
				<< std::numeric_limits<float>::max() << '\n'<< std::endl;
}
