
#include <iostream>
#include <string>
#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <list>

std::list<std::string> split(std::string &str, char delimiter) {
	std::stringstream			sstr(str);
	std::string					token;
	std::list<std::string>	result;
	while (std::getline(sstr, token, delimiter)){
		result.push_back(token);
	}
	return result;
}

int ft_strlen(char *str) {
	int i = 0;

	if (!str)
		return 0;
	while (str[i])
		i++;
	return i;
}

bool isNotDigit(char c) {
	return !std::isdigit(c);
}

void pairAndSort(std::vector<int>& _src) {
	std::vector<int> tmp(_src);
	std::vector<std::pair<std::vector<int>, std::vector<int> > > vpairv;  // Para almacenar los pares
	size_t n = _src.size();
	size_t j = 1;  // Comenzamos con pares de 2
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
/* 		std::cout << "LEVEL: " << j/2 << ": ";
		std::vector<int>::iterator iter;
		for (iter = tmp.begin(); iter != tmp.end(); iter++) {
			std::cout << *iter << " ";
		}
		std::cout << std::endl; */
		if (j==0)
			j = 1;
		j *= 2;
	}
	_src.swap(tmp);
}

void insertion(std::vector<int> &_src) {
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

std::vector <int> sort(std::vector<int> _src) {
	size_t n = _src.size();
	std::vector<std::pair<int , int> > pairsn1;
	std::pair<int, int> pairn1;
	std::vector<std::pair<std::pair<int ,int>, std::pair<int ,int> > > pairsn2;
	std::pair<std::pair<int,int>, std::pair<int,int> > pairn2;
	std::vector<std::pair<std::pair<std::pair<int,int> ,std::pair<int,int> >, std::pair<std::pair<int,int> ,std::pair<int,int> > > > pairsn3;
	std::pair<std::pair<std::pair<int,int> ,std::pair<int,int> >, 
				std::pair<std::pair<int,int> ,std::pair<int,int> > >  pairn3;
	std::vector<std::pair<std::pair<std::pair<std::pair<int,int>,std::pair<int,int> >, std::pair<std::pair<int,int>,std::pair<int,int> > >, 
				std::pair<std::pair<std::pair<int,int>,std::pair<int,int> >, std::pair<std::pair<int,int>,std::pair<int,int> > > > > pairsn4;
	std::pair<std::pair<std::pair<std::pair<int,int>,std::pair<int,int> >, std::pair<std::pair<int,int>,std::pair<int,int> > >, 
				std::pair<std::pair<std::pair<int,int>,std::pair<int,int> >, std::pair<std::pair<int,int>,std::pair<int,int> > > >  pairn4;

	std::vector< std::pair<std::vector<int>, std::vector<int> > > vpairv;
	std::pair<std::vector<int>, std::vector<int> > pairv;


	std::vector<int>::iterator it;
	for (size_t i = 0; i  + 1 < n; i += 2) {
		pairn1 =  std::make_pair(_src[i], _src[i + 1]);
		if (pairn1.first > pairn1.second)
			std::swap(pairn1.first, pairn1.second);
		pairsn1.push_back(pairn1);
	}
	if (_src.size() % 2 != 0)
		pairsn1.push_back(std::make_pair(_src.back(), -1));
	
	for (size_t i = 0; i + 1 < n / 2; i += 2) {
		pairn2 = std::make_pair(pairsn1[i], pairsn1[i + 1]);
		if (pairn2.first.second > pairn2.second.second)
			std::swap(pairn2.first, pairn2.second);
		pairsn2.push_back(pairn2);
	}
	if (_src.size() / 2 % 2 != 0)
		pairsn2.push_back(std::make_pair(pairsn1.back(), std::make_pair(-1, -1)));

	for (size_t i = 0; i + 1 < n / 4; i += 2) {
		pairn3 = std::make_pair(pairsn2[i], pairsn2[i + 1]);
		if (pairn3.first.second.second > pairn3.second.second.second)
			std::swap(pairn3.first, pairn3.second);
		pairsn3.push_back(pairn3);
	}
	if (_src.size() / 4 % 2 != 0)
		pairsn3.push_back(std::make_pair(pairsn2[(n / 4) - 1], pairsn2.back()));

	for (size_t i = 0; i + 1 < n / 6; i += 2) {
		pairn4 = std::make_pair(pairsn3[i], pairsn3[i + 1]);
		if (pairn4.first.second.second > pairn4.second.second.second)
			std::swap(pairn4.first, pairn4.second);
		pairsn4.push_back(pairn4);
	}
	if (_src.size() / 6 % 2 != 0)
		pairsn4.push_back(std::make_pair(pairsn3.back(), std::make_pair(std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1)),std::make_pair(std::make_pair(-1, -1),std::make_pair(-1, -1)) )));


	std::vector<std::pair<std::pair<std::pair<int,int> ,std::pair<int,int> >, std::pair<std::pair<int,int> ,std::pair<int,int> > > > ::iterator pit;
	for (pit = pairsn3.begin(); pit != pairsn3.end(); pit++) {
		std::cout	<< "[[["
					<< pit->first.first.first
					<< " , "
					<< pit->first.first.second
					<< "],["
					<< pit->first.second.first
					<< " , "
					<< pit->first.second.second
					<< "],["
					<< pit->second.first.first
					<< " , "
					<< pit->second.first.second
					<< "],["
					<< pit->second.second.first
					<< " , "
					<< pit->second.second.second
					<< "]]]"
					<< std::endl;
	}

	std::cout << "-----------------------N4---------------------" << std::endl;
		std::vector<std::pair<std::pair<std::pair<std::pair<int,int>,std::pair<int,int> >, std::pair<std::pair<int,int>,std::pair<int,int> > >, 
				std::pair<std::pair<std::pair<int,int>,std::pair<int,int> >, std::pair<std::pair<int,int>,std::pair<int,int> > > > > ::iterator pit4;
	for (pit4 = pairsn4.begin(); pit4 != pairsn4.end(); pit4++) {
		std::cout	<< "[[[["
					<< pit4->first.first.first.first
					<< " , "
					<< pit4->first.first.first.second
					<< "],["
					<< pit4->first.first.second.first
					<< " , "
					<< pit4->first.first.second.second
					<< "],["
					<< pit4->first.second.first.first
					<< " , "
					<< pit4->first.second.first.second
					<< "],["
					<< pit4->first.second.second.first
					<< " , "
					<< pit4->first.second.second.second
					<< "],["
					<< pit4->second.first.first.first
					<< " , "
					<< pit4->second.first.first.second
					<< "],["
					<< pit4->second.first.second.first
					<< " , "
					<< pit4->second.first.second.second
					<< "],["
					<< pit4->second.second.first.first
					<< " , "
					<< pit4->second.second.first.second
					<< "],["
					<< pit4->second.second.second.first
					<< " , "
					<< pit4->second.second.second.second
					<< "]]]]"
					<< std::endl;
	}
	return _src;
}

int main(int argc, char **arg) {
	std::vector<int> nums;
	if (argc < 2)
		return std::cout << "Error" << std::endl, 1;

	//Parser arg to vector<int>
	for (int i = 1; i < argc; i++)
	{
		std::string str(arg[i]);
		std::list<std::string> s_numbers = split(str, ' ');
		std::list<std::string>::iterator it;
		for (it = s_numbers.begin(); it != s_numbers.end(); ++it) {
			std::string &current = *it;
			std::string::iterator nonDigit = std::find_if(current.begin(), current.end(), isNotDigit);
			if (nonDigit != current.end())
				return std::cout << "Contain non digit in arg" << current << std::endl, 1;
			int val = atoi(current.c_str());
			if (val < 0)
				return std::cout << "Error" << std::endl, 1;
			nums.push_back(val);
		}
	}
	if (nums.size() <= 0)
		return std::cout << "Error: Invalid number of arguments" << std::endl,1;

	std::cout << "Before: "<< std::endl;
	for (size_t k = 0 ; k < nums.size(); k++){
		std::cout << nums[k] << " ";
	}
	std::cout << std::endl;
	pairAndSort(nums);
	std::cout << "After Pair sort: "<< std::endl;
	for (size_t k = 0 ; k < nums.size(); k++){
		std::cout << nums[k] << " ";
	}
	std::cout << std::endl;
	insertion(nums);
	std::cout << "After Insertion sort : "<< std::endl;
	for (size_t k = 0 ; k < nums.size(); k++){
		std::cout << nums[k] << " ";
	}
	std::cout << std::endl;
}