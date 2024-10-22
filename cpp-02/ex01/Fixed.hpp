#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

#include <stdint.h>
/*
Multiplicacion
resultado=(A×B)>>fraccionario_bits
Division
resultado=(A×2^fraccionario_bits)/B

_fixed_point_t=parte_entera×2^16 + fractional_bits×2^16

part_entera = _fixed_point_t >> fractional_bits;
*/
class Fixed {
	private:
		int				_fixed_point_t;
		static const int	_fractional_bits;
	public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed& fixed);
	~Fixed();
	int		getRawBits() const;
	void	setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed& operator=(const Fixed& fixed);
	friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif