
#include "Span.hpp"

#include <stdlib.h>
#include <memory>
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <climits>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define MAX_VAL 15000
Span val10m(MAX_VAL);

std::string arrToStr(const char *val)
{
	int i = -1;
	std::stringstream ss;
	while (val[++i])
		ss << val[i];
	return ss.str();
}

std::string intToStr(int val)
{
	std::stringstream ss;
		ss << val;
	return ss.str();
}

int writeTruncFile(std::string _content)
{
	std::ofstream outFile("logs", std::ios::trunc);

	if (!outFile){
		std::cout << "Error to open file: "<< "logs" << std::endl;
		return 1;
	}
	outFile << _content;
	outFile.close();
	return 0;
}

void build_span_max_val()
{
	std::string content;
	srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++) {
		const int val = rand();
		val10m.addNumber(val);
		content +=  arrToStr("[") + intToStr(i) + arrToStr("]") + intToStr(val) + arrToStr("\n");

	}
	writeTruncFile(content);
}

void test_mandatory()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "min: " << sp.getValMin() << std::endl;
	std::cout << "max: " << sp.getValMax() << std::endl;
	std::cout << GREEN << "test_mandatory: PASSED!" << RESET <<  std::endl;
}

void test_addNumber()
{

	Span sp = Span(5);

	std::cerr << RED;
	sp.addNumber(6);
	assert(sp[0] == 6);
	sp.addNumber(3);
	assert(sp[1] == 3);
	sp.addNumber(17);
	assert(sp[2] == 17);
	sp.addNumber(9);
	assert(sp[3] == 9);
	sp.addNumber(11);
	assert(sp[4] == 11);
	std::cerr << RESET;
	std::cout << GREEN << "test_addNumber: PASSED!" << RESET <<  std::endl;
}

void test_addNumber_exception()
{
	Span spn;
	try {
		spn.addNumber(10);
	} catch(std::exception & e) {
		std::string str = "Error: Invalid Arg";
		std::cerr << RED;
		assert( e.what() == str);
		std::cerr << RESET;
	}
	std::cout << GREEN << "test_addNumber_exception: PASSED!" << RESET <<  std::endl;
}

void test_addRange_exception()
{
	Span spn;
	Span spn10m(MAX_VAL);
	try {
		spn.addRange(val10m.begin(), val10m.end());
	} catch (std::overflow_error &e ) {
		std::string str = "Error: Span is full";
		std::cerr << RED ;
		assert( e.what() == str);
		std::cerr << RESET ;
	}
	spn10m.addRange(val10m.begin(), val10m.end());
	try {
		spn10m.addRange(val10m.begin(), val10m.end());
	} catch (std::overflow_error &e ) {
		std::string str = "Error: Span is full";
		std::cerr << RED ;
		assert( e.what() == str);
		std::cerr << RESET ;
	}
	std::cout << GREEN << "test_addRange_exception: PASSED!" << RESET <<  std::endl;
}

void test_addRange()
{

	Span spn10m(MAX_VAL);
	spn10m.addRange(val10m.begin(), val10m.end() - MAX_VAL / 2);
	spn10m.addRange(val10m.end() - MAX_VAL / 2, val10m.end());
	std::cerr << RED;
	assert(spn10m.getValMax() == val10m.getValMax());
	assert(spn10m.getValMin() == val10m.getValMin());
	assert(*spn10m.begin() == *val10m.begin());
	std::cerr << RESET;
	std::cout << GREEN << "test_addRange: PASSED!" << RESET <<  std::endl;
}

void test_shortestSpan()
{
	Span spn(3);
	spn.addNumber(452);
	spn.addNumber(1552);
	spn.addNumber(124552);

	assert(spn.shortestSpan() == 1552 - 452);
	std::cout << GREEN << "test_shortestSpan: PASSED!" << RESET <<  std::endl;
}

void test_shortestSpan_exception()
{
	Span spn(1);
	spn.addNumber(10);
	try {
		spn.shortestSpan();
	} catch (std::exception & e) {
		std::string str = "Error: There are not enough numbers";
		std::cerr << RED ;
		assert(e.what() == str);
		std::cerr << RESET ;
	}
	Span spn2;
	try {
		spn2.shortestSpan();
	} catch (std::invalid_argument & e) {
		std::string str = "Error: There are not enough numbers";
		std::cerr << RED ;
		assert(e.what() == str);
		std::cerr << RESET ;
	}
	std::cout << GREEN << "test_shortestSpan_exception: PASSED!" << RESET <<  std::endl;
}

void test_longestSpan()
{
	Span spn(3);
	spn.addNumber(452);
	spn.addNumber(1552);
	spn.addNumber(124552);

	assert(spn.longestSpan() == 124552 - 452);
	std::cout << GREEN << "test_longestSpan: PASSED!" << RESET <<  std::endl;
}

void test_longestSpan_exception()
{
	Span spn(1);
	spn.addNumber(10);
	try {
		spn.longestSpan();
	} catch (std::exception & e) {
		std::string str = "Error: There are not enough numbers";
		std::cerr << RED ;
		assert(e.what() == str);
		std::cerr << RESET ;
	}
	Span spn2;
	try {
		spn2.longestSpan();
	} catch (std::invalid_argument & e) {
		std::string str = "Error: There are not enough numbers";
		std::cerr << RED ;
		assert(e.what() == str);
		std::cerr << RESET ;
	}
	std::cout << GREEN << "test_longestSpan_exception: PASSED!" << RESET <<  std::endl;

}

void test_max_max_val()
{
	Span spn(3);
	int randval[3];
	int valmax = INT_MIN;
	for (int i = 0; i < 3; i++) {
		randval[i] = rand();
		if (valmax < randval[i])
			valmax = randval[i];
	}
	spn.addNumber(randval[0]);
	assert(spn.getValMax() == randval[0]);
	spn.addNumber(randval[1]);
	assert(spn.getValMax() == ((randval[0] > randval[1]) ? randval[0]: randval[1]));
	spn.addNumber(randval[2]);
	assert(spn.getValMax() == valmax);
	std::cout << GREEN << "test_max_max_val: PASSED!" << RESET <<  std::endl;

}

void test_min_max_val()
{
	Span spn(3);
	int randval[3];
	int valmin = INT_MAX;
	for (int i = 0; i < 3; i++) {
		randval[i] = rand();
		if (valmin > randval[i])
			valmin = randval[i];
	}
	spn.addNumber(randval[0]);
	assert(spn.getValMin() == randval[0]);
	spn.addNumber(randval[1]);
	assert(spn.getValMin() == ((randval[0] < randval[1]) ? randval[0]: randval[1]));
	spn.addNumber(randval[2]);
	assert(spn.getValMin() == valmin);
	std::cout << GREEN << "test_min_max_val: PASSED!" << RESET <<  std::endl;

}

void test_assignment_op_exception(){
	Span sp;
	sp = val10m;

	assert(sp.getValMax() == val10m.getValMax());
	assert(sp.getValMin() == val10m.getValMin());
	assert(sp.longestSpan() == val10m.longestSpan());
	assert(sp.shortestSpan() == val10m.shortestSpan());
	assert(sp[0] == val10m[0]);
	sp[0] += 3;
	assert(sp[0] != val10m[0]);

	sp = sp;
	assert(&sp == &sp, && "Error: Should be Equal direction of Span in assignment");
	std::cout << GREEN << "test_copy_build: PASSED!" << RESET <<  std::endl;

}

void test_index_op() {
	Span sp;
	try {
		sp[0] += 3;
	} catch (std::exception &e) {
		std::string str = "Error: Index is out of bounds";
		std::cerr << RED ;
		assert(e.what() == str);
		std::cerr << RESET ;

	}
	std::cout << GREEN << "test_index_op: PASSED!" << RESET <<  std::endl;

}

void test_copy_build(){
	Span sp(val10m);

	assert(sp.getValMax() == val10m.getValMax());
	assert(sp.getValMin() == val10m.getValMin());
	assert(sp.longestSpan() == val10m.longestSpan());
	assert(sp.shortestSpan() == val10m.shortestSpan());
	assert(sp[0] == val10m[0]);
	sp[0] += 3;
	assert(sp[0] != val10m[0]);

	std::cout << GREEN << "test_copy_build: PASSED!" << RESET <<  std::endl;

}
int main()
{
	build_span_max_val();
	test_mandatory();
	test_addNumber();
	test_addNumber_exception();
	test_addRange_exception();
	test_addRange();
	test_shortestSpan();
	test_shortestSpan_exception();
	test_longestSpan();
	test_longestSpan_exception();
	test_max_max_val();
	test_min_max_val();

	test_copy_build();
	test_assignment_op_exception();
	test_index_op();
	return 0;
}