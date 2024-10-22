#ifndef CONTACTREPOSITORYINMEMORY_HPP
#define CONTACTREPOSITORYINMEMORY_HPP

#include "../core/PhoneBook.hpp"
#include "../contact/Contact.hpp"
#include <vector>

class PhoneBookRepositoryInMemory : public PhoneBookRepository {
private:
    Contact* contacts;
    int n_contacts;

public:
    PhoneBookRepositoryInMemory(): contacts(new Contact[9]), n_contacts(0){}
    ~PhoneBookRepositoryInMemory(){
        delete[] contacts;
    }
    void addContact(Contact nContact);
    int nContacts();
    Contact *getAllContacts();
    Contact* findContact(int index);
    void exit();
};

#endif
