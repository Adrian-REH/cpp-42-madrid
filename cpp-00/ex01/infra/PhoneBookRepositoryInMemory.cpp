#include "PhoneBookRepositoryInMemory.hpp"
#include <iostream>
#include <iomanip>


Contact *PhoneBookRepositoryInMemory::getAllContacts() {
    return (contacts);
}

void PhoneBookRepositoryInMemory::addContact(Contact nContact) {
    if (n_contacts < 8)
    {
        for (int i = 0; i < 9; ++i) {
            if (contacts[i].isEmpty()) {
                contacts[i] = nContact;
                n_contacts++;
                return;
            }
        }
    }
    else
        contacts[8] = nContact;
}

int PhoneBookRepositoryInMemory::nContacts() {
    return n_contacts;
}

Contact* PhoneBookRepositoryInMemory::findContact(int index) {

    for (int i = 0; i < 9; ++i) {
        if (contacts[i].getIndex() == index) {
            return &contacts[i];
        }
    }
    return NULL;
}

void PhoneBookRepositoryInMemory::exit()
{
    std::cout << "Exiting PhoneBook application..." << std::endl;
}
