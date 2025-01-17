/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConvert.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:41:20 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 20:22:38 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATCONVERT_HPP
#define FLOATCONVERT_HPP
#include <string>
#include <iostream>
#include <limits>

class FloatConvert {
	private:
		FloatConvert();
		FloatConvert(const FloatConvert &);
		~FloatConvert();
		FloatConvert & operator=(const FloatConvert &);
	public:
		static void convertFloat(std::string);
};

#endif