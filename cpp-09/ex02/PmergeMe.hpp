#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <set>
#include <vector>

class PmergeMe {
	private:
		std::multiset<int> f;
		PmergeMe();
	public:
		PmergeMe(char **arg);
		void sort();
};

#endif