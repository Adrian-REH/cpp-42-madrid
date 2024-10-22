#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club("Manticore lance");
		HumanA bob("Bob", club);
		
		bob.attack();
		club.setType("Silver heart lance");
		bob.attack();
	}
	{
		Weapon club("Aileen Bow");
		HumanB lily("Lily", club);

		lily.attack();
		club.setType("Sylph Wind Bow");
		lily.attack();
	}
}