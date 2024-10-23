/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:53:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:53:28 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{
private:
    int index_;
    std::string firstName_;
    std::string lastName_;
    std::string nickName_;
    std::string phoneNumber_;
    std::string darkestSecret_;

public:
    void setIndex(const int& index) {
        if (index >= 0 && index < 9)
            index_ = index;
    }
    void setFirstName(const std::string& firstName) {
        if (!firstName.empty())
            firstName_ = firstName;
    }

    void setLastName(const std::string& lastName) {
        if (!lastName.empty())
            lastName_ = lastName;
    }

    void setNickName(const std::string& nickname) {
        if (!nickname.empty())
            nickName_ = nickname;
    }
    void setPhoneNumber(const std::string& phoneNumber) {
        if (!phoneNumber.empty())
            phoneNumber_ = phoneNumber;
    }
    void setDarkestSecret(const std::string& darkestSecret) {
        if (!darkestSecret.empty())
            darkestSecret_ = darkestSecret;
    }
    int getIndex() const {
        return index_;
    }
    std::string getFirstName() const {
        return firstName_;
    }

    std::string getLastName() const {
        return lastName_;
    }

    std::string getNickName() const {
        return nickName_;
    }

    std::string getPhoneNumber() const {
        return phoneNumber_;
    }

    std::string getDarkestSecret() const {
        return darkestSecret_;
    }
    bool isEmpty() const {
        return (firstName_.empty() || lastName_.empty() || nickName_.empty() || phoneNumber_.empty() || darkestSecret_.empty()|| (index_ < 0 && index_ >= 9));
    }
   bool operator==(const Contact& other) const {
        return (getFirstName() == other.getFirstName() &&
                getLastName() == other.getLastName() &&
                getNickName() == other.getNickName() &&
                getPhoneNumber() == other.getPhoneNumber() &&
                getDarkestSecret() == other.getDarkestSecret());
                // Agrega más comparaciones según los atributos que necesites.
    }

    std::string formatColumn(const std::string& text, long unsigned int width) {
        if (text.size() > width) {
            return text.substr(0, width - 1) + ".";
        } else {
            return std::string(width - text.length(), ' ') + text;
        }
    }
    void diplaySimple() {
        std::cout << std::setw(10)<< index_ << "|"
                  << formatColumn(firstName_, 10) << "|"
                  << formatColumn(lastName_, 10) << "|"
                  << formatColumn(nickName_, 10) << std::endl;
    }
    void display() const {
        std::cout << "First Name: " << firstName_ << std::endl;
        std::cout << "Last Name: " << lastName_ << std::endl;
        std::cout << "Nickname: " << nickName_ << std::endl;
        std::cout << "Phone Number: " << phoneNumber_ << std::endl;
        std::cout << "Darkest Secret: " << darkestSecret_ << std::endl;
    }
};

#endif

