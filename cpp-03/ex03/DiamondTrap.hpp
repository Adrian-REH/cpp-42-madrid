#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap(std::string _name);
		~DiamondTrap();
		void attack(const std::string& target);
		void whoAmI();
};

#endif