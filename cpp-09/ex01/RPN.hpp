#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>

enum EOperator {
	PLUS,
	MINUS,
	MULTIPLICATION,
	DIVISION,
	INVALID_OPERATOR
};

enum ETokenType {
	NUMBER,
	OPERATOR,
	SPACE,
	END,
	INVALID,
};


class RPN {
	private:
		int		_first;
		int		_second;
		int		_result;
		EOperator	_operator;
		int plus();
		int minus();
		int division();
		int multipli();
	public:
		RPN();
		~RPN();
		RPN(const RPN&);
		RPN &operator=(const RPN&);
		int getFirst() const;
		int getSecond() const;
		int	getResult() const;
		EOperator getOperator() const;
		void	setFirst(int first);
		void	setSecond(int second);

		int	resolve(char c);
};

std::ostream & operator<<(std::ostream &io, const RPN &);

#endif