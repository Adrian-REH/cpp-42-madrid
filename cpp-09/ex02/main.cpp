#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>


int main(int argc, char **arg) {
	clock_t end;
	clock_t start;

	PmergeMe<std::vector<int> > pmergevect(argc, arg);
    start = clock();
	std::vector<int> bfvect = pmergevect.getSrc();
	std::vector<int> aftvect = pmergevect.sort();
    end = clock();
	std::vector<int>::iterator itv;
    double duration_two = double(end - start) / CLOCKS_PER_SEC ;

	std::cout << "Before: ";
	for (itv = bfvect.begin() ; itv != bfvect.end(); itv++) {
		std::cout << *itv << " ";
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (itv = aftvect.begin() ; itv != aftvect.end(); itv++)
		std::cout << *itv << " ";
	std::cout << std::endl;

	PmergeMe<std::list<int> > pmergelst(argc, arg);
    start = clock();
	std::list<int> before = pmergelst.getSrc();
	std::list<int> result = pmergelst.sort();
    end = clock();
	std::list<int>::iterator itl;
    double duration_one = double(end - start) / CLOCKS_PER_SEC ;

    std::cout << "Tiempo para procesar el rango de " << result.size()<<" elementos con std::list<int>: "
            <<std::fixed << std::setprecision(6) << duration_one << " us" << std::endl;
    std::cout << "Tiempo para procesar el rango de " <<result.size()<<" elementos con std::vector<int>: "
               <<std::fixed << std::setprecision(6) << duration_two << " us" << std::endl;

}