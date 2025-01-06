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
