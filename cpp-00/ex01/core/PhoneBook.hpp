// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../contact/Contact.hpp"
#include "PhoneBookRepository.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
private:
    PhoneBookRepository& contactRepo;
public:
    PhoneBook(PhoneBookRepository& repo);
    void addContact(Contact nContact);
    int nContacts();
    Contact* findContact(int index);
    void exit();
};

#endif
