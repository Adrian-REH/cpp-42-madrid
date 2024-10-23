/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:01:18 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:02:05 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <stdint.h>

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