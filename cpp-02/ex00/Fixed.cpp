
#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int val) : _fixed_point_t(val)
{
	std::cout << "Default constructor called" << std::endl;
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

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_t;
}

void Fixed::setRawBits(int const raw) {
	_fixed_point_t = raw;
}