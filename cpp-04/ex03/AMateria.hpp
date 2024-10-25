#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"
class AMateria
{
	protected:
		int			_idx;
		std::string _type;
	public:
		AMateria(std::string const &type);
		std::string const &getType() const;
		int const &getIdx() const;
		void setIdx(int);
		bool isEmpty();

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif