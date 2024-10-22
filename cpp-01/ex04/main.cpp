
#include "File.hpp"
#include <iostream>

int	main()
{
	File file = File("file.txt");
	std::string str = file.getContent();
	file.readFile();
	file.replace("Holaa!", "Holaa! ");
	file.writeTruncFile();
}