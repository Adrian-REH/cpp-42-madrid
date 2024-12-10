/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:55:51 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:23:25 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DoubleConvert.hpp"

void DoubleConvert::convertDouble(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	double it = strtod(val, &endptr);
	std::cout << "double:\t"<< it << std::endl;
}
