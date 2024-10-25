/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:02:41 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 20:09:11 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include "bsp.cpp"
#include <iostream>
/**     C
 *    /   \
 *   /     \
 *  /       \
 * A_ _ _ _ _B
 * A = ( 0 , 0 )
 * B = ( 10 , 0 )
 * C = ( 5 , 4 )
 * • Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on edge, it will return False.
 */
int main()
{
	Point const	c( Fixed(5) , Fixed(4) );
	Point const	a( Fixed(0) , Fixed(0) );
	Point const	b( Fixed(10) , Fixed(0) );
	Point const	point( Fixed(5) , Fixed(3) );

	if (bsp(a, b, c, point))
		std::cout << "The point is inside a triangle" << std::endl;
	else
		std::cout << "The point is not inside a triangle" << std::endl;
	return 0;
}
