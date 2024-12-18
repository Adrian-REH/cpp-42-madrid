#include "PmergeMe.hpp"

int main(int argc, char **arg) {
	PmergeMe sorted(argc, arg);
	std::vector<int> result = sorted.sort();
	std::cout << "Before: "<< std::endl;
	for (size_t k = 0 ; k < result.size(); k++){
		std::cout << result[k] << " ";
	}
}