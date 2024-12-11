/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:06:23 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 16:25:38 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stddef.h>
#include <vector>
#include <string>
#include <algorithm> 
#include <exception> 
#include "easyfind.hpp"


int main () {
	int	const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	std::vector<int> src(w, w + w_size);

	try {
		std::cout << easyfind<std::vector<int> >(src, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
