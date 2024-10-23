/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:26:40 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 03:59:59 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	cross_product( Point init, Point end, Point point)
{
	Fixed a(end.getY() - init.getY());
	Fixed b(end.getX() - init.getX());
	Fixed c(end.getX() * init.getY() - init.getX() * end.getY());
	return (a * point.getX() - b * point.getY() + c);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed ab(cross_product( a, b, point));
	Fixed bc(cross_product( b, c, point));
	Fixed ca(cross_product( c, a, point));

	if (ab > 0 && bc > 0 && ca > 0)
		return true;
	if (ab < 0 && bc < 0 && ca < 0)
		return true;

	return false;
}
