/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:00:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:00:45 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	if (argc != 2)
	{
		std::cout << "Probably complaining about insignificant problems" << std::endl;
		return 0;
	}
	Harl harl = Harl();
	harl.complain(argv[1]);
	harl.~Harl();
}