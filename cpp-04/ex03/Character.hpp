#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		static int			n_materias;
		std::string			_name;
		AMateria *_materias[4];
	public:
		Character(std::string);
		~Character();
		std::string const & getName();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
#endif