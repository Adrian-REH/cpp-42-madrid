/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactBuilder.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:53:22 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 12:42:59 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_BUILDER_HPP
#define CONTACT_BUILDER_HPP

#include "Contact.hpp"

class ContactBuilder  {
private:
    Contact contact_;
public:
    ContactBuilder() {
        contact_ = Contact();
    }

    ContactBuilder& firstName(const std::string& firstName) {
        contact_.setFirstName(firstName);
        return *this;
    }

    ContactBuilder& lastName(const std::string& lastName) {
        contact_.setLastName(lastName);
        return *this;
    }

    ContactBuilder& nickName(const std::string& nickName) {
        contact_.setNickName(nickName);
        return *this;
    }

    ContactBuilder& phoneNumber(const std::string& phoneNumber) {
        contact_.setPhoneNumber(phoneNumber);
        return *this;
    }

    ContactBuilder& darkestSecret(const std::string& darkestSecret) {
        contact_.setDarkestSecret(darkestSecret);
        return *this;
    }

    Contact build() {
        return contact_;
    }
};

#endif