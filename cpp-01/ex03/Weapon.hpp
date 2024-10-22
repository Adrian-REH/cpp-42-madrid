#ifndef WEEAPON_HPP
#define WEEAPON_HPP
#include <string>

class Weapon{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		std::string getType(void);
};

#endif