#include <stdexcept>
#include "RPN.hpp"
#include <iostream>
#include <stack>


bool isoperator(char c)
{
	return (42 == c || 43 == c || c == 45 || 47 == c);
}

ETokenType identifyRPN(char c)
{
	if (isdigit(c))
		return NUMBER;
	else if (isoperator(c))
		return OPERATOR;
	else if (isspace(c))
		return SPACE;
	else if (c == 0)
		return END;
	else
		return INVALID;
}

void resolve(std::stack<int> &sint, char c) {
	RPN rpn;
	if (sint.size() < 2)
		throw std::invalid_argument("There are no arguments to operate");
	rpn.setFirst(sint.top());
	sint.pop();
	rpn.setSecond(sint.top());
	sint.pop();
	sint.push(rpn.resolve(c));
}
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
	int				i = 0;
	int				state[2] = {3, 3};

	if ( argc != 2)
		return std::cout << "Error: not valid argument" << std::endl, 1;
	do 
	{
		state[1] = identifyRPN(arg[1][i]);
		if (state[1] == INVALID || \
		(state[0] == NUMBER && state[1] == NUMBER) || \
		(state[0] == OPERATOR && state[1] == OPERATOR)) {
			std::cout << "Error" << std::endl;
			return 1;
		}
		if (state[0] == NUMBER && state[1] == SPACE)
			sint.push(arg[1][i - 1] - 48);
		else if (state[0] == (int)OPERATOR && (state[1] == (int)SPACE || state[1] == (int)END)){
			try {
				resolve(sint, arg[1][i - 1]);
			} catch (std::exception &e){
				std::cout << e.what() << std::endl;
				return 1;
			}
		}
		state[0] = state[1];
	}
	while ((arg[1][i++]));
	std::cout << sint.top() << std::endl;
}