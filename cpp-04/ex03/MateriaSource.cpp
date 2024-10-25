
#include "MateriaSource.hpp"
int MateriaSource::n_materias = 0;

MateriaSource::MateriaSource(){

}

MateriaSource::~MateriaSource(){
}
void MateriaSource::learnMateria(AMateria * materia){
	if (!_materias[n_materias - 1]->isEmpty())
	{
		materia->setIdx(n_materias);
		_materias[n_materias - 1] = materia;
		n_materias++;
		return ;
	}
}
AMateria* createMateria(std::string const & type)
{
	AMateria newAM = new AMateria(type);
}
