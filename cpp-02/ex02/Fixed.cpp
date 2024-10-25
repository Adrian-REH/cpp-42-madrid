/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:01:41 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:59:52 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractional_bits = 8;
const float Fixed::_epsilon = 1.0f / (1 << _fractional_bits);

Fixed::Fixed() : _fixed_point_t(0)
{
}

Fixed::Fixed(const int val)
{
	_fixed_point_t = static_cast<int>(val * (1 << _fractional_bits));
}

Fixed::Fixed(const float val)
{
	_fixed_point_t = static_cast<int>(roundf(val * (1 << _fractional_bits)));
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed::~Fixed(){
}

Fixed& Fixed::operator=(const Fixed& fixed){
	if (this != &fixed){
		this->_fixed_point_t = fixed._fixed_point_t;
	}
	return *this;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(_fixed_point_t) / (1 << _fractional_bits));
}

int Fixed::toInt( void ) const {
	return (static_cast<int>(_fixed_point_t) / (1 << _fractional_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits() const {
	return _fixed_point_t;
}

void Fixed::setRawBits(int const raw) {
	_fixed_point_t = raw;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a >= b)
		return (b);
	return (a);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a.toFloat() >= b.toFloat())
		return (b);
	return (a);
}
Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a <= b)
		return (b);
	return (a);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a.toFloat() <= b.toFloat())
		return (b);
	return (a);
}
bool Fixed::operator>(const Fixed& fixed){
	return (this->_fixed_point_t > fixed._fixed_point_t);
}
bool Fixed::operator>=(const Fixed& fixed){
	return (this->toFloat() >= fixed.toFloat());
}
bool Fixed::operator<(const Fixed& fixed){
	return (this->_fixed_point_t < fixed._fixed_point_t);
}
bool Fixed::operator<=(const Fixed& fixed){
	return (this->_fixed_point_t <= fixed._fixed_point_t);	
}
bool Fixed::operator==(const Fixed& fixed){
	return (this->_fixed_point_t == fixed._fixed_point_t &&\
	this->_fractional_bits == this->_fractional_bits);	
}

bool Fixed::operator!=(const Fixed& fixed){
	return (this->_fixed_point_t != fixed._fixed_point_t &&\
		this->_fractional_bits != fixed._fractional_bits);
}
Fixed Fixed::operator+(const Fixed& fixed){
	Fixed result(this->toFloat() + fixed.toFloat());
	return result;
}
Fixed Fixed::operator-(const Fixed& fixed){
	Fixed result( this->toFloat() - fixed.toFloat());
	return result;
}
//resultado=(A×B)>>fraccionario_bits
Fixed Fixed::operator*(const Fixed& fixed){
	Fixed result(static_cast<float>(this->toFloat() * fixed.toFloat()));
	return result;
}
//resultado=(A×2^fraccionario_bits)/B
Fixed Fixed::operator/(const Fixed& fixed){
	if (fixed._fixed_point_t == 0)
		throw std::runtime_error("Division by zero");
	Fixed result( this->toFloat() / fixed.toFloat());
	return result;
}
Fixed Fixed::operator++(){
	this->_fixed_point_t += static_cast<int>(_epsilon * (1 << _fractional_bits));
	return *this;
}
Fixed Fixed::operator++(const int){
	Fixed tmp = *this;
	this->_fixed_point_t += static_cast<int>(_epsilon * (1 << _fractional_bits));
	return tmp;
}
Fixed Fixed::operator--(){
	this->_fixed_point_t -= static_cast<int>(_epsilon * (1 << _fractional_bits));
	return *this;
}
Fixed Fixed::operator--(const int){
	Fixed tmp = *this;
	this->_fixed_point_t -= static_cast<int>(_epsilon * (1 << _fractional_bits));
	return tmp;
}