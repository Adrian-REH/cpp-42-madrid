#include "PmergeMe.hpp"
#include "split.hpp"


template <typename T>
PmergeMe<T>::PmergeMe(): _src(0) {}
template <typename T>
PmergeMe<T>::PmergeMe(int length, char **arg) : _src(0)
{
	parser(length, arg);
	if (_src.size() <= 1)
		throw std::invalid_argument("Error: Invalid number of arguments");
}
template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> & src) : _src(src._src) {}

template <typename T>
PmergeMe<T> & PmergeMe<T>::operator=(PmergeMe<T> const &src) {
	if (this == &src)
		return *this;
	this->_src = src._src;
	return *this;
}

bool isNotDigit(char c) {
	return !std::isdigit(c);
}

template <typename T>
void PmergeMe<T>::merge() {
	T tmp(_src);
	typename T::iterator it;
	std::vector<std::pair<T, T> > vpairv;
	typename T::iterator itpair;
	size_t n = _src.size();
	size_t j = 1;
	std::pair<T, T> pair;

	while (n >= j) {
		T left, right;
		vpairv.clear();
		for (size_t i = 0; i < n; i += 2*j)
		{
			left.clear();
			right.clear();
			for (unsigned long k = i; left.size() < j; k++) {
				if (!(k < i + j && k < n))
				{
					left.push_back(-1);
					continue ;
				}
				it = tmp.begin();
				std::advance(it, k);
				left.push_back(*it);
			}
			for (unsigned long k = i + j; right.size() < j; ++k) {
				if (!(k < i + 2 * j && k < n))
				{
					right.push_back(-1);
					continue ;
				}
				it = tmp.begin();
				std::advance(it, k);
				right.push_back(*it);
			}
			pair = std::make_pair(left, right);
			if (pair.first.back() > pair.second.back() && pair.first.back() != -1 && pair.second.back() != -1)
				std::swap(pair.first, pair.second);
			vpairv.push_back(pair);
		}
		tmp.clear();
		for (unsigned long i = 0 ; i < vpairv.size(); i++) {
			for (unsigned long k = 0; k < vpairv[i].first.size(); ++k) {
				itpair = vpairv[i].first.begin();
				std::advance(itpair, k);
				if (*itpair != -1)
					tmp.push_back(*itpair);
			}
			for (unsigned long k = 0; k < vpairv[i].second.size(); ++k) {
				itpair = vpairv[i].second.begin();
				std::advance(itpair, k);
				if (*itpair != -1)
					tmp.push_back(*itpair);
			}
		}
		if (j==0)
			j = 1;
		j *= 2;
	}

	_src.swap(tmp);
}

template <typename T>
void PmergeMe<T>::insertion() {
	std::vector<T> result;
	T sorted;
	typename T::iterator it;
	size_t n = _src.size();
	size_t j = 1;

	while (j <= n)
		j *= 2;
	j /= 4;
	while (j >= 1) {
		T block;
		result.clear();
		for (size_t i = 0; i < n; i += j) {
			block.clear();
			for (size_t k = i; block.size() < j; k++) {
				if (!(k < i + 2 * j && k < n))
				{
					block.push_back(-1);
					continue ;
				}
				it = _src.begin();
				std::advance(it, k);
				block.push_back(*it);
			}
			result.push_back(block);
		}
		for (size_t i = 0; i < result.size() ; i++) {
			for (size_t k = i + 1; k < result.size(); k++) {
				if (result[i].back() > result[k].back() && result[i].back() != -1) {
					std::swap(result[i], result[k]);
				}
			}
		}
		sorted.clear();
		for (size_t i = 0; i < result.size() ; i++) {
			sorted.insert(sorted.end(), result[i].begin(), result[i].end());
		}
		j /= 2;
	}
	_src.swap(sorted);
}

template <typename T>
void PmergeMe<T>::parser(int argc, char **arg) {
	typename T::iterator it;
	for (int i = 1; i < argc; i++)
	{
		std::string str(arg[i]);
		std::vector<std::string> s_numbers = split(str, ' ');
		
		std::vector<std::string>::iterator it;
		for (it = s_numbers.begin(); it != s_numbers.end(); ++it) {

			std::string &current = *it;
			std::string::iterator nonDigit = std::find_if(current.begin(), current.end(), isNotDigit);
			if (nonDigit != current.end()) {
				throw std::invalid_argument("Error: Contain non digit in arg");
			}
			int val = atoi(current.c_str());
			if (val < 0) {
				std::cout << "Error" << std::endl;
				throw std::invalid_argument("Error: Contain negative digit");
			}
			_src.push_back(val);
		}
	}
}

template <typename T>
T PmergeMe<T>::sort() {
	merge();
	insertion();
	return _src;
}

template <typename T>
T PmergeMe<T>::getSrc() {
	return _src;
}

template <typename T>
void PmergeMe<T>::isSorted(){
	size_t size = _src.size();

	for (int i = 0; i < size; i++) {
		if (_src[i] > _src[i + 1]) {
			std::cout << "El vector no está ordenado." << std::endl;
			return;
		}
	}
	std::cout << "Success!: The vector is sorted." << std::endl;
}

template <typename T>
std::ostream & operator<<(std::ostream &io, PmergeMe<T> &val) {
	T src = val.getSrc();
	size_t size = src.size();

	io << "VALUES" << std::endl;
	for (size_t i = 0; i < size; i++) {
		io << src[i] << " ";
	}
	io << std::endl;
	val.isSorted();
	return io;
}
