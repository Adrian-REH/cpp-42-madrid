/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:33:39 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:22:07 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include "../inc/CharConvert.hpp"
#include "../inc/IntConvert.hpp"
#include "../inc/FloatConvert.hpp"
#include "../inc/DoubleConvert.hpp"

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(std::string src) {
	(void)src;
	CharConvert chrConv;
	IntConvert intConv;
	FloatConvert floatConv;
	DoubleConvert doubleConv;
	chrConv.convertChar(src);
	intConv.convertInt(src);
	floatConv.convertFloat(src);
	doubleConv.convertDouble(src);
}
