/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:53:37 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:53:43 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/PhoneBook.hpp"

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
