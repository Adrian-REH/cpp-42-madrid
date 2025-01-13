#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>


int main(int argc, char **arg) {

	PmergeMe<std::list<int> > pmergelst(argc, arg);
    clock_t start = clock();
	std::list<int> before = pmergelst.getSrc();
	std::list<int> result = pmergelst.sort();
    clock_t end = clock();
	std::list<int>::iterator it;
    double duration_one = double(end - start) / CLOCKS_PER_SEC ;


	PmergeMe<std::vector<int> > pmergevect(argc, arg);
    start = clock();
	std::vector<int> bfvect = pmergevect.getSrc();
	std::vector<int> aftvect = pmergevect.sort();
    end = clock();
    double duration_two = double(end - start) / CLOCKS_PER_SEC ;


	std::cout << "Before: " << std::endl;
	for (it = before.begin() ; it != before.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << "After: " << std::endl;
	for (it = result.begin() ; it != result.end(); it++) {
		std::cout << *it << " ";
	}



    std::cout << "Tiempo para procesar el rango de 5 elementos con std::list<int>: "
            <<std::fixed << std::setprecision(6) << duration_one << " us" << std::endl;
    std::cout << "Tiempo para procesar el rango de 5 elementos con std::vector<int>: "
               <<std::fixed << std::setprecision(6) << duration_two << " us" << std::endl;

}