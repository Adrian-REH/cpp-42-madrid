/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:40:06 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/18 18:34:03 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <deque>
#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(T src) : std::stack<T>(std::deque<T>(src)) {}
		~MutantStack() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		MutantStack &operator=(MutantStack const &other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}
};

#endif