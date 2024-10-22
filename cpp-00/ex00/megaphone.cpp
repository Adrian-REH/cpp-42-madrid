#include <iostream>
#include <cctype>
#include <string>

void stoupper(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j] != 0; ++j)
			std::cout << static_cast<char>(toupper(argv[i][j]));
		std::cout<<" ";
	}
	std::cout<<std::endl;
}
int main(int argc, char *argv[])
{
	stoupper(argc, argv);
	return (0);
}