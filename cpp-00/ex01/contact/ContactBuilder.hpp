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

    // Cambiar el tipo de retorno a ContactBuilder&
    ContactBuilder& firstName(const std::string& firstName) {
        contact_.setFirstName(firstName);
        return *this; // Devuelve la referencia al objeto actual
    }

    ContactBuilder& lastName(const std::string& lastName) {
        contact_.setLastName(lastName);
        return *this; // Devuelve la referencia al objeto actual
    }

    ContactBuilder& nickName(const std::string& nickName) {
        contact_.setNickName(nickName);
        return *this; // Devuelve la referencia al objeto actual
    }

    ContactBuilder& phoneNumber(const std::string& phoneNumber) {
        contact_.setPhoneNumber(phoneNumber);
        return *this; // Devuelve la referencia al objeto actual
    }

    ContactBuilder& darkestSecret(const std::string& darkestSecret) {
        contact_.setDarkestSecret(darkestSecret);
        return *this; // Devuelve la referencia al objeto actual
    }

    // El método build() no necesita cambios
    Contact build() {
        return contact_;
    }
};

#endif