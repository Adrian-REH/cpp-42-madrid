#ifndef FIXED_HPP
#define FIXED_HPP

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
	Fixed(int);
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator=(const Fixed& fixed);
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif