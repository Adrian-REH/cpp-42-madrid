/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:26:44 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/30 16:21:03 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(Fixed x, Fixed y);
		Point(const int fpx, const int fpy);
		~Point();
		Point(const Point& fixed);
		Fixed getX() const;
		Fixed getY() const;
		void setX(Fixed);
		void setY(Fixed);
		Point& operator=(const Point& point);
};

#endif