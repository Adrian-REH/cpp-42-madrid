/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConvert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:25:53 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CharConvert.hpp"

void CharConvert::convertChar(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	
	std::cout << "type\t│ lowest()\t│ min()\t\t│ max()\n"
				<< "uchar\t│ "
				<< +std::numeric_limits<char>::lowest() << "\t\t│ "
				<< +std::numeric_limits<char>::min() << "\t\t│ "
				<< +std::numeric_limits<char>::max() << std::endl;
}