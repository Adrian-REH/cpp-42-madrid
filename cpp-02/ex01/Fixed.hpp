/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:01:31 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:01:56 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

#include <stdint.h>

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