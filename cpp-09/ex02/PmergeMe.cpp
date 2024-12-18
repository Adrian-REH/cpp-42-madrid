#include "PmergeMe.hpp"
#include "split.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int length, char **arg)
{
	parser(length, arg);
	if (_src.size() <= 1)
		throw std::invalid_argument("Error: Invalid number of arguments");
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & src) : _src(src._src) {}

PmergeMe & PmergeMe::operator=(PmergeMe const &src) {
	if (this == &src)
		return *this;
	this->_src = src._src;
	return *this;
}

bool isNotDigit(char c) {
	return !std::isdigit(c);
}

void PmergeMe::merge() {
	std::vector<int> tmp(_src);
	std::vector<std::pair<std::vector<int>, std::vector<int> > > vpairv;
	size_t n = _src.size();
	size_t j = 1;
	std::pair<std::vector<int>, std::vector<int> > pair;

	while (n >= j) {
		std::vector<int> left, right;
		vpairv.clear();
		for (size_t i = 0; i + 1 < n; i += 2*j)
		{
			left.clear();
			right.clear();
			for (size_t k = i; left.size() < j; k++) {
				if (!(k < i + j && k < n))
				{
					left.push_back(-1);
					continue ;
				}
				left.push_back(tmp[k]);
			}
			for (size_t k = i + j; right.size() < j; ++k) {
				if (!(k < i + 2 * j && k < n))
				{
					right.push_back(-1);
					continue ;
				}
				right.push_back(tmp[k]);
			}
			pair = std::make_pair(left, right);
			if (pair.first.back() > pair.second.back() && pair.first.back() != -1 && pair.second.back() != -1)
				std::swap(pair.first, pair.second);
			vpairv.push_back(pair);
		}
		tmp.clear();
		for (size_t i = 0 ; i < vpairv.size(); i++) {
			for (size_t k = 0; k < vpairv[i].first.size(); ++k) {
				if (vpairv[i].first[k] != -1)
					tmp.push_back(vpairv[i].first[k]);
			}
			for (size_t k = 0; k < vpairv[i].second.size(); ++k) {
				if (vpairv[i].second[k] != -1)
					tmp.push_back(vpairv[i].second[k]);
			}
		}
		if (j==0)
			j = 1;
		j *= 2;
	}
	_src.swap(tmp);
}

void PmergeMe::insertion() {
	std::vector<std::vector<int> > result;
	std::vector<int> sorted;
	size_t n = _src.size();
	size_t j = 1;  // Comenzamos con pares de 2
	while (j <= n)
		j *= 2;
	j /= 4;
	while (j >= 1) {
		std::vector<int> block;
		result.clear();
		for (size_t i = 0; i + 1 < n; i += j) {
			block.clear();
			for (size_t k = i; block.size() < j; k++) {
				if (!(k < i + 2 * j && k < n))
				{
					block.push_back(-1);
					continue ;
				}
				block.push_back(_src[k]);
			}
			result.push_back(block);
		}
		for (size_t i = 0; i < result.size() ; i++) {
			for (size_t k = 0; k < result.size(); k++) {
				if (result[i].back() < result[k].back() && result[i].back() != -1) {
					std::vector<int> temp(result[i]);
					result.erase(result.begin() + i);
					result.insert(result.begin() + k, temp);
					if (i < k)
						i--;
					break ;
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

void PmergeMe::parser(int argc, char **arg) {
	for (int i = 1; i < argc; i++)
	{
		std::string str(arg[i]);
		std::list<std::string> s_numbers = split(str, ' ');
		std::list<std::string>::iterator it;
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

std::vector<int> PmergeMe::sort() {
	merge();
	insertion();
	return _src;
}
