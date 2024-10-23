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
		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
};
#endif