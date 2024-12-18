#include "split.hpp"

std::list<std::string> ft_split(std::string &str, char delimiter) {
	std::stringstream			sstr(str);
	std::string					token;
	std::list<std::string>	result;
	while (std::getline(sstr, token, delimiter)){
		result.push_back(token);
	}
	return result;
}
