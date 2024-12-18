/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:22:54 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/17 21:35:36 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main() {
	int a = 2; int b = 3; 
	::swap( a, b ); 
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl; 
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1"; 
	std::string d = "chaine2"; 
	::swap(c, d); 
	std::cout << "c = " << c << ", d = " << d << std::endl; 
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl; 
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0; 
}
