#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include "split.hpp"
#include <cstdlib>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
class PmergeMe {
	private:
		T _src;
		void parser(int argc, char **arg);
		void merge();
		void insertion();
		PmergeMe();
	public:
		PmergeMe(int argc, char **arg);
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe & operator=(PmergeMe const &);
		T sort();
		T getSrc();
		void isSorted();
};

template <typename T>
std::ostream & operator<<(std::ostream &io, PmergeMe<T> &val);

#include "PmergeMe.tpp"
#endif