#include "split.hpp"
#include <iostream>
std::vector<std::string> split(std::string &str, char delimiter) {
	std::stringstream			sstr(str);
	std::string					token;
	std::vector<std::string>	result;
	token.clear();
	for (size_t i = 0; i < str.size(); i++){
		if (str[i] == delimiter) {
			if (!token.empty())
			{
				result.push_back(token);
				token.clear();
			}
		} else 
			token += str[i];

	}
	if (!token.empty()) {
		result.push_back(token);
	}
	return result;
}
