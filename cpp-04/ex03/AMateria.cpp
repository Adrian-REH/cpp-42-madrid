
#include "AMateria.hpp"

AMateria::AMateria(std::string const &type){}
std::string const & AMateria::getType() const{}

AMateria* AMateria::clone()const {}
void AMateria::use(ICharacter& target){}
