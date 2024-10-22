#include "../core/PhoneBook.hpp"


// Constructor que usa el repositorio de contactos
PhoneBook::PhoneBook(PhoneBookRepository& repo) : contactRepo(repo) {}


void PhoneBook::addContact(Contact nContact) {
    if (nContact.isEmpty())
    {
        std::cout << "Complete todos los campos" << std::endl;
        return ;
    }
    contactRepo.addContact(nContact);
}

int PhoneBook::nContacts() {

    return contactRepo.nContacts();
}

Contact* PhoneBook::findContact(int index) {

    return contactRepo.findContact(index);
}

void PhoneBook::exit() {
    contactRepo.exit();
}
