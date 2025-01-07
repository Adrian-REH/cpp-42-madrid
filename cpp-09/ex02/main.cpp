#include "PmergeMe.hpp"

int main(int argc, char **arg) {
	PmergeMe sorted(argc, arg);
	std::vector<int> result = sorted.sort();
	std::vector<int>::iterator it;
	std::cout << "Before: "<< std::endl;


	for (it = result.begin() ; it != result.end(); it++) {
		std::cout << *it << " ";
	}
}