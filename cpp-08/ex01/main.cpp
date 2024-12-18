
#include "Span.hpp"

#include <stdlib.h>
#include <memory>
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define MAX_VAL 10000
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

void handle_test( std::string msg, bool pass) {
	if (!pass) {
		std::cerr << RED << "Error:" << msg << RESET << std::endl;
		assert(pass);
	}
}

void build_span_max_val() {
	std::string content;
	srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++) {
		const int val = rand();
		val10m.addNumber(val);
		content +=  arrToStr("[") + intToStr(i) + arrToStr("]") + intToStr(val) + arrToStr("\n");

	}
	writeTruncFile(content);
}

void test_mandatory(){
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

void test_addNumber(){

}


void test_addNumber_exception(){
	Span spn;
	try {
		spn.addNumber(10);
	} catch(std::exception & e) {
		std::string str = "Error: Invalid Arg";
		handle_test("", e.what() == str);
	}
	std::cout << GREEN << "test_addNumber_exception: PASSED!" << RESET <<  std::endl;
}

void test_addRange(){
	Span spn;

	spn.addRange(spn.begin(), spn.end());
}

void test_shortestSpan_exception() {
	
}

void test_longestSpan_exception() {

}

void test_max_10000vals(){

}

void test_min_10000val(){

}

void test_15000nums(){

}

int main() {
	build_span_max_val();
	test_mandatory();
	test_addNumber_exception();
	return 0;
}