
#include "AMateria.hpp"

AMateria::AMateria(std::string const &type){
	if (type == "ice")
		_type = "Ice";
	if (type == "cure")
		_type = "Cure";
}
std::string const & AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target){}
