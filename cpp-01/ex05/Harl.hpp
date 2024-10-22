#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl{ 
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		static void (Harl::*_k[4])(void);
		static std::string _states[4];
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif