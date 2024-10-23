/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookRepositoryInMemory.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:54:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 12:10:10 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTREPOSITORYINMEMORY_HPP
#define CONTACTREPOSITORYINMEMORY_HPP

#include "../core/PhoneBook.hpp"
#include "../contact/Contact.hpp"
#include <vector>

class PhoneBookRepositoryInMemory : public PhoneBookRepository {
private:
    Contact* contacts;
    static int n_contacts;

public:
    PhoneBookRepositoryInMemory(): contacts(new Contact[8]){}
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
