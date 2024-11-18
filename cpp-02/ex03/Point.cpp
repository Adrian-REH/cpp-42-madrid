/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:26:50 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/18 13:33:01 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){

}

Point::Point(Fixed x, Fixed y): _x(x), _y(y){

}
Point::Point(const int fpx, const int fpy): _x(Fixed(fpx)), _y(Fixed(fpy)) {
}
Point::~Point(){

}

Point::Point(const Point& point): _x(point.getX()) , _y(point.getY()){

}

Point& Point::operator=(const Point& point){
	if (this == &point)
		return *this;
	return *this;
}

Fixed Point::getX() const {
	return (_x);
}

Fixed Point::getY() const{
	return (_y);
}
