/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookRepository.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:53:53 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:54:12 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTREPOSITORY_HPP
#define CONTACTREPOSITORY_HPP

#include "../contact/Contact.hpp"
#include <iostream>

class PhoneBookRepository {
public:
    virtual void addContact(Contact nContact) = 0;
    virtual int nContacts() = 0;
    virtual Contact *getAllContacts() = 0;
    virtual Contact* findContact(int index) = 0;
    virtual void exit() = 0;
};

#endif