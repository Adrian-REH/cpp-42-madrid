/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:06:23 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/18 19:33:15 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stddef.h>
#include <vector>
#include <string>
#include <algorithm> 
#include <exception> 
#include <cassert>
#include "easyfind.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


void test_find_should_return_target() {
	int	const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	std::vector<int> src(w, w + w_size);

	int result = easyfind<std::vector<int> >(src, 275);
	assert(result == 275);
	result = easyfind<std::vector<int> >(src, 657);
	assert(result == 657);
	result = easyfind<std::vector<int> >(src, 321);
	assert(result == 321);
	std::cout << GREEN << "test_find_should_return_target: PASSED!" << RESET <<  std::endl;
}

void test_find_should_return_exception() {
	int	const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	std::vector<int> src(w, w + w_size);

	try {
		easyfind<std::vector<int> >(src, 10000);
	} catch (std::exception &e) {
		std::string str = "Error: Not found";
		assert(str == e.what());
	}
	std::cout << GREEN << "test_find_should_return_exception: PASSED!" << RESET <<  std::endl;
}
void test_find_then_src_null_should_return_exception() {
	std::vector<int> src;

	try {

		easyfind<std::vector<int> >(src, 275);
	} catch (std::exception & e) {
		std::string str = "Error: No arguments";
		assert(str == e.what());

	}

	std::cout << GREEN << "test_find_then_src_null_should_return_target: PASSED!" << RESET <<  std::endl;
}

int main () {
	test_find_should_return_target();
	test_find_should_return_exception();
	test_find_then_src_null_should_return_exception();
}
