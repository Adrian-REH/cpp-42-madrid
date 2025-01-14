/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:22:54 by adherrer          #+#    #+#             */
/*   Updated: 2025/01/14 14:48:00 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ScalarConverter.hpp"
#include <iostream>
#include <sstream>


std::string arrToStr(char *val)
{
	int i = -1;
	std::stringstream ss;
	while (val[++i])
		ss << val[i];
	return ss.str();
}


#include <iostream>
#include <limits>
 
int main(int argc, char **argv) {
	
	if (argc != 2) {
		std::cout << "The arguments to be converted were not sent" << std::endl;
		return 0;
	}

/*     std::cout << "-------------------LIMITS--------------------"<< std::endl;
    std::cout << "type\t│ min()\t\t│ max()\n"
              << "char\t│ "
              << +std::numeric_limits<char>::min() << "\t\t│ "
              << +std::numeric_limits<char>::max() << '\n'
              << "int\t│ "
              << std::numeric_limits<int>::min() << "\t│ "
              << std::numeric_limits<int>::max() << '\n'
              << "float\t│ "
              << std::numeric_limits<float>::min() << "\t│ "
              << std::numeric_limits<float>::max() << '\n'
              << "double\t│ "
              << std::numeric_limits<double>::min() << "\t│ "
              << std::numeric_limits<double>::max() << '\n';
    std::cout << "---------------------------------------"<< std::endl; */
	ScalarConverter::convert(arrToStr(argv[1]));
}
