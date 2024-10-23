/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:26:44 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 03:52:01 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point(Fixed x, Fixed y);
		Point(const int fpx, const int fpy);
		~Point();
		Point(const Point& fixed);
		Fixed getX();
		Fixed getY();
		Point& operator=(const Point& point);
};

#endif