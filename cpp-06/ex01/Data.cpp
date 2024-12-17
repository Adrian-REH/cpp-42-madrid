#include "Data.hpp"
#include <iostream>
#include <string>

Data::Data(){
	std::cout << "[Build] Data class" << std::endl;
}

Data::~Data() {
	std::cout << "[Destroyed] Data class" << std::endl;
}

Data::Data(std::string name) : _name(name){
	std::cout << "[Build] Data class" << std::endl;
}


Data::Data(const Data & data) {
	std::cout << "[Copy] Copy Data class called" << std::endl;
	*this = data;
}

std::string Data::getName() const {
	return (this->_name);
}

Data &Data::operator=(const Data & data) {
	std::cout << "operator assignament called" << std::endl;
	if (&data != this)
		return *this;
	this->_name = data.getName();
	return *this;
}
