#include "PmergeMe.hpp"

int main(int argc, char **arg) {

	PmergeMe<std::list<int> > pmergelst(argc, arg);
	std::list<int> before = pmergelst.getSrc();
	time_t initlst = time(NULL);
	std::list<int> result = pmergelst.sort();
	time_t endlst = time(NULL);
	std::list<int>::iterator it;




	PmergeMe<std::vector<int> > pmergevect(argc, arg);
	std::vector<int> bfvect = pmergevect.getSrc();
	time_t initvect = time(NULL);
	std::vector<int> aftvect = pmergevect.sort();
	time_t endvect = time(NULL);


	std::cout << "Before: " << std::endl;
	for (it = before.begin() ; it != before.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << "After: " << std::endl;
	for (it = result.begin() ; it != result.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << "Time to process a range of 5 elements with std::list<int> : " << endlst - initlst << std::endl;
	std::cout << "Time to process a range of 5 elements with std::list<int> : " << endlst - initlst << std::endl;
	std::cout << "Time to process a range of 5 elements with std::vector<int> : " << endlst - initlst << std::endl;
	std::cout << "Time to process a range of 5 elements with std::vector<int> : " << endvect - initvect << std::endl;
}