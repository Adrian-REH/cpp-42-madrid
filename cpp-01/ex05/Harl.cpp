#include "Harl.hpp"
#include <iostream>
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void (Harl::*Harl::_k[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
std::string Harl::_states[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::complain(std::string level)
{
	int i = 0;
	while (_states[i] != level)
		i++;
	if (i >= 4)
	{
		std::cout << "Probably complaining about insignificant problems" << std::endl;
		return ;
	}
	(this->*_k[i])();
}

void Harl::debug()
{
	std::cout << GREEN << "[DEBUG]" << RESET
	<<" I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout<< BLUE << "[INFO]" << RESET
	<< " I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout<< YELLOW << "[WARNING]"<< RESET
	<< " I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month" << std::endl;
}

void Harl::error()
{
	std::cout<< RED << "[ERROR]" << RESET
	<< " This is unacceptable! I want to speak to the manager now" << std::endl;
}
