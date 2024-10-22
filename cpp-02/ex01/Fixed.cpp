
#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	std::cout << "Constructor int called" << std::endl;
	_fixed_point_t = static_cast<int>(val *(1 << _fractional_bits));
}

Fixed::Fixed(const float val)
{
	std::cout << "Constructor float called" << std::endl;
	_fixed_point_t = static_cast<int>(roundf(val * (1 << _fractional_bits)));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called"<< std::endl;
	*this = fixed;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed){
	if (this != &fixed){
		std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_t;
}

void Fixed::setRawBits(int const raw) {
	_fixed_point_t = raw;
}