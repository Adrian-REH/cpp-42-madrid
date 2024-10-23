/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:00:25 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:00:26 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include <iostream>

int	main()
{
	File file = File("file.txt");
	std::string str = file.getContent();
	file.readFile();
	file.replace("Holaa!", "Holaa! ");
	file.writeTruncFile();
}