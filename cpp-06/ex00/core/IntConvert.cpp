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

void IntConvert::convertInt(std::string str) {
	char* endptr = NULL;
	const char* val = str.c_str();
	int it = atol(val);

	std::cout << "type\t│ lowest()\t│ min()\t\t│ max()\n"
				<< "int\t│ "
				<< std::numeric_limits<int>::lowest() << "\t│ "
				<< std::numeric_limits<int>::min() << "\t│ "
				<< std::numeric_limits<int>::max() << '\n' << std::endl;

}
