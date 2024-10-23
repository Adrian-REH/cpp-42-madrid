/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:53:47 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:53:48 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
