/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:06 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/25 16:18:41 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& brain);
		Brain& operator=(const Brain& brain);
		~Brain();
		void display();
		Brain *clone();
		std::string getIdea(int idx);
		void getIdeas();
		void setIdea(int idx, std::string idea);
};
#endif