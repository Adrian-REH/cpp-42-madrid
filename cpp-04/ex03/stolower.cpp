#include "stolower.hpp"

std::string stolower(std::string src)
{
	for (size_t i = 0 ; i < src.size() ; ++i)
		src[i] = std::tolower(src[i]);
	return src;
}