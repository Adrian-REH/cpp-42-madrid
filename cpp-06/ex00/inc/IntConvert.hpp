/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConvert.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:41:20 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 20:22:39 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTCONVERT_HPP
#define INTCONVERT_HPP
#include <string>
#include <iostream>
#include <limits>

class IntConvert {
	private:
		IntConvert();
	public:
		static void convertInt(std::string);
};

#endif