#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <set>
#include <vector>
#include "split.hpp"
#include <cstdlib>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int> _src;
		void parser(int argc, char **arg);
		void merge();
		void insertion();
		PmergeMe();
	public:
		PmergeMe(int argc, char **arg);
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe & operator=(PmergeMe const &);
		std::vector<int> sort();
};

#endif