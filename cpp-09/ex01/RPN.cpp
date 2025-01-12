#include "RPN.hpp"

RPN::RPN() : _first(0), _second(0), _result(0), _operator(INVALID_OPERATOR){
	//std::cout << "[Build] RPN" << std::endl;
}

RPN::~RPN() {
	//std::cout << "[Destroy] RPN" << std::endl;
}
RPN::RPN(const RPN& src) {
	*this = src;
}

RPN &RPN::operator=(const RPN& src) {
	if (this == &src)
		return *this;
	this->_first = src.getFirst();
	this->_second = src.getSecond();
	this->_result = src.getResult();
	this->_operator = src.getOperator();
	return *this;
}

int RPN::plus() {
	return this->_first + this->_second;
}

int RPN::minus() {
	return this->_first - this->_second;
}

int RPN::division() {
	if (this->_second == 0)
		throw std::invalid_argument("It is not possible to divide by zero");
	return (this->_first / this->_second);
}

int RPN::multipli() {
	return this->_first * this->_second;
}

int RPN::getFirst() const {
	return this->_first;
}

int RPN::getSecond() const {
	return this->_second;
}

int	RPN::getResult() const {
	return this->_result;
}

EOperator RPN::getOperator() const {
	return this->_operator;
}

void RPN::setFirst(int first) {
	this->_first = first;
}

void RPN::setSecond(int second) {
	this->_second = second;
}

int	RPN::resolve(char c) {
	switch(c) {
		case '+': return plus();
		case '-': return minus();
		case '*': return multipli();
		case '/': return division();
		default: throw std::invalid_argument("Invalid operator");
	}
}

std::ostream & operator<<(std::ostream &io, const RPN &val) {
	io << "DATA" << std::endl;
	io << "First: " << val.getFirst() << std::endl;
	io << "Operator: " << val.getOperator() << std::endl;
	io << "Second: " << val.getSecond() << std::endl;
	io << "Result: " << val.getResult() << std::endl;
	return (io);
}

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

int resolve(std::queue<int> &sint, char c) {
	RPN rpn;
	if (sint.size() < 2)
		throw std::invalid_argument("There are no arguments to operate");
	rpn.setFirst(sint.front());
	sint.pop();
	rpn.setSecond(sint.front());
	sint.pop();
	sint.push(rpn.resolve(c));
	return 0;
}

int ft_pushnbr(std::queue<int> & sint, char c) {
	sint.push(c - 48);
	return 0;
}
int ft_error(std::queue<int> &sint, char c) {
	(void)sint;
	std::cout << "Error: " << c << std::endl;
	return 1;
}