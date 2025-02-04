#include <stdexcept>
#include "RPN.hpp"
#include <iostream>



/**
 * The program name is RPN. 
• Your program must take an inverted Polish mathematical expression as an argument. 
• The numbers used in this operation and passed as arguments will always be less than 10. 
The calculation itself but also the result do not take into account this rule. 
• Your program must process this expression and output the correct result on the standard output. 
• If an error occurs during the execution of the program an error message should be displayed on the standard output. 
• Your program must be able to handle operations with these tokens: "+- / *".
	recomendalb eusar stack
 */
int main(int argc, char **arg)
{
	std::stack<int>	sint;
	try {
	// NUMBER	OPERATOR	SPACE	END	INVALID
	int (*f[5][5])(std::stack<int>&, char) = {
		{ft_error, ft_error, ft_pushnbr, ft_pushnbr, NULL},	// NUMBER
		{ft_error, ft_error, resolve, resolve, NULL},		// OPERATOR
		{NULL, NULL, NULL, NULL, NULL},					// SPACE
		{NULL, NULL, NULL, NULL, NULL},					// END
		{ft_error, ft_error, ft_error, ft_error, ft_error}					// INVALID
	};
	int				i = 0;
	int				state[2] = {3, 3};

	if ( argc != 2)
		return std::cout << "Error: not valid argument" << std::endl, 1;
	do
	{
		state[1] = identifyRPN(arg[1][i]);
		if (f[state[0]][state[1]])
		{
			try {
				if (f[state[0]][state[1]](sint, arg[1][i - 1]))
					return 1;
			} catch (std::exception &e){
				std::cout << e.what() << std::endl;
				return 1;
			}
		}
		state[0] = state[1];
	}
	while ((arg[1][i++]));
	if (sint.size() > 1)
		return (std::cout << "Error: There are more numbers than operators" << std::endl, 1);
	if (!sint.empty())
		std::cout << sint.top() << std::endl;
	}catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
