/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:22:54 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/17 20:01:17 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void ft_apply(T& val) {
	std::cout << val << std::endl;
	return val;
}

int main() {

	std::string strs[4] = { "¿Hola " ,"Como ", "Estas?", ", Adios!"};
	iter<std::string> (strs, 4, ft_apply<std::string>);
	return 0;

}
