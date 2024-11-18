/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:52:51 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/18 18:54:51 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal(std::string);
		Animal(const Animal& animal);
		Animal();
		virtual ~Animal();
		Animal& operator=(const Animal& animal);
		virtual std::string getType() const;
		virtual void makeSound() const;
};

#endif