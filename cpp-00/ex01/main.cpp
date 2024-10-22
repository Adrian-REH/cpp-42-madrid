#include "core/PhoneBook.hpp"
#include "infra/PhoneBookRepositoryInMemory.hpp"
#include "contact/Contact.hpp"
#include "contact/ContactBuilder.hpp"
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int displayContacts(Contact *contacts)
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;
    for (int i = 0; !contacts[i].isEmpty(); ++i)
		contacts[i].diplaySimple();
    std::cout << std::string(44, '-') << std::endl;
	return 0;
}

std::string stdinval(std::string msg)
{
	std::string val;
	while (val.empty())
	{
		std::cout << "Ingrese su " << msg;
		if (!(std::cin >> val)) {
			return "";
		}
		if (val.empty())
			std::cout << RED << "Entrada vacia"<< RESET << std::endl;
	}
	return (val);
}

std::string displayopc()
{
    std::string opc;
	std::cout 
    << std::left <<CYAN << std::setw(10) << "1. ADD" <<std::endl
    << std::left << std::setw(10) << "2. SEARCH"<<std::endl
    << std::left << std::setw(10) << "3. EXIT" <<std::endl;
	std::cout << YELLOW <<std::string(44, '-')  <<std::endl;
	std::cout  << "Enter the opc: ";
	if (!(std::cin >> opc)) {
		std::cout << RED << "EOF detected, exiting...\n"<< RESET;
		return "";
	}
	return opc;
}
int main() {
    std::string opc;
    PhoneBookRepositoryInMemory repo;
    PhoneBook phoneBook(repo);

	while (1)
	{
		opc = displayopc();
		if (opc.empty())
			return 0;
		if (!opc.compare("ADD"))
		{
			std::cout << YELLOW <<std::string(44, '-') <<std::endl;
			Contact newContact = ContactBuilder()
			.firstName(stdinval("First Name: "))
			.lastName(stdinval("Last Name: "))
			.nickName(stdinval("Nick Name: "))
			.phoneNumber(stdinval("Phone Number: "))
			.darkestSecret(stdinval("Dark Secret: "))
			.build();
			phoneBook.addContact(newContact);
			std::cout<<std::endl << GREEN << "¡Contacto agregado correctamente!" <<std::endl;
			std::cout << YELLOW <<std::string(44, '-') <<std::endl;
			std::cout << RESET;
			continue;
		}
		else if (!opc.compare("SEARCH"))
		{
			std::cout << YELLOW <<std::string(44, '-') <<std::endl;
			std::cout << "Enter the index of the contact to display: ";
			int index;
			std::cin >> index;
			std::cout << BLUE;
			if (index >= 0 && index < phoneBook.nContacts()) {
				Contact* cont =  phoneBook.findContact(index);
				std::cout << std::endl;
				displayContacts(cont);
				std::cout << std::string(44, '-') << std::endl;
				cont[index].display();
			} else {
				std::cout<<RED << "Invalid index. Please try again." << RESET <<std::endl;
			}
			std::cout << YELLOW <<std::string(44, '-') <<std::endl;
			std::cout << RESET;
			continue;
		}
		else if (!opc.compare("EXIT"))
		{
			phoneBook.exit();
			break ;
		}
		else{
			std::cout << RED << "Invalid OPC. Please try again." << RESET << std::endl;
			continue;
		}
	}
	return 0;
}