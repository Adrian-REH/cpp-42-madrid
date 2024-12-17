/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:44:44 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 02:13:55 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <stdlib.h>
#include <cassert>
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"
#define MAX_VAL 10

void test_build_array() {
	Array<int> numbers(MAX_VAL);
	Array<int> *numbers2 = new Array<int>[MAX_VAL]();
	delete [] numbers2;
}

void test_add_element() {
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL]();
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		std::cout<< "["<< i << "] " << numbers[i] << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++)
		assert(mirror[i] == numbers[i] && "test_add_element: FAILED: size should be 10" );
	assert(numbers.size() == 10 && "test_add_element: FAILED: size should be 10" );
	std::cout << GREEN << "test_add_element: PASSED" << RESET<< std::endl;
	delete [] mirror;
}


void test_copy_array() {
	Array<int> numbers(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
	}

	Array<int> tmp;
	tmp = numbers;
	assert(tmp.size() == numbers.size() && "test_copy_array: FAILED: Size should be 10.");
	assert(tmp[0] == numbers[0] && "test_copy_array: FAILED: Data of temp in pos 0 should be equal to pos 0 of numbers.");
	Array<int> test(numbers);
	assert(test.size() == numbers.size() && "test_empty_stack: FAILED: Size should be 10.");
	assert(test[0] == numbers[0] && "test_copy_array: FAILED: Data of test in pos 0 should be equal to pos 0 of numbers.");
	std::cout << GREEN << "test_copy_array: PASSED" << RESET<< std::endl;
}

void test_opindex_exception_out_of_range() {
	Array<int> number;

	try {
		number[-1];
	} catch (std::exception &e) {
		std::string result = "Error: Index is out of bounds";

		assert(e.what() == result && "test_exception_out_of_range: FAILED: Error should be out of range");
	}
	try
	{
		number[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::string result = "Error: Index is out of bounds";
		assert(e.what() == result  && "test_exception_out_of_range: FAILED: Error should be out of range");
	}
	std::cout << GREEN << "test_exception_out_of_range: PASSED" << RESET<< std::endl;
}

void test_op_index_assignment() {
	
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL]();
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		std::cout<< "["<< i << "] " << numbers[i] << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
		std::cout<< "["<< i << "] " << numbers[i] << std::endl;
	}
	delete [] mirror;
}

int main()
{
	test_build_array();
	test_add_element();
	test_copy_array();
	test_opindex_exception_out_of_range();
	test_op_index_assignment();

	return 0;
}