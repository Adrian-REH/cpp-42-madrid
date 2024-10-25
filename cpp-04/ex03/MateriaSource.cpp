
#include "MateriaSource.hpp"
#include <string>
#include <iostream>

int MateriaSource::n_materias = 0;

void stolower(std::string src)
{
	for (char &c : src)
		c = std::tolower(c);
}

MateriaSource::MateriaSource(){}

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria * materia){
	if (!_materias[n_materias - 1]->isEmpty())
	{
		materia->setIdx(n_materias);
		_materias[n_materias - 1] = materia;
		n_materias++;
		std::cout << "Saved" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	stolower(type);
	AMateria *result = 0;
	for(int i = 0; i < 4; i++)
	{
		if (_materias[i]->getType() == type)
			return (_materias[i]);
	}
	return 0;
}
