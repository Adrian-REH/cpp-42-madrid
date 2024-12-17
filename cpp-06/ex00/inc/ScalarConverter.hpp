/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:15:03 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:29:35 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <string>
#include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter &);
	public:
		static void convert(std::string);
};

#endif