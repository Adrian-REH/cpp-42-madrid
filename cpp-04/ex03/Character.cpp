
#include "ICharacter.hpp"

ICharacter::~ICharacter(){}
std::string const & ICharacter::getName(){}
void ICharacter::equip(AMateria* m) {}
void ICharacter::unequip(int idx) {}
void ICharacter::use(int idx, ICharacter &target){}
