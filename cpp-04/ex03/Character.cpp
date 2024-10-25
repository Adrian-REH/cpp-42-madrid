
#include "Character.hpp"

int Character::n_materias = 0;

Character::Character(std::string name) : _name(name) {}

Character::~Character(){
	delete[] _materias;
}
std::string const & Character::getName(){
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!_materias[n_materias - 1]->isEmpty())
	{
		m->setIdx(n_materias);
		_materias[n_materias - 1] = m;
		n_materias++;
		return ;
	}
}

void Character::unequip(int idx) {
	if (idx > n_materias || idx < 0)
		return ;
	for (int i = 0; i < 4; i++ )
	{
		if (_materias[i]->getIdx() == idx)
			_materias[i] = 0;
	}
}
void Character::use(int idx, ICharacter &target){
	if (idx > n_materias || idx < 0)
		return ;
}
