#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
class ClapTrap {
	private:
		std::string	_name;
		int			_hit_point;
		int			_energy;
		int			_attack_damage;
	public:
		ClapTrap(std::string);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
#endif