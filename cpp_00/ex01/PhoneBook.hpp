
#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int     _index;
        std::string  formatField(std::string str);
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    addContact(void);
        void    displayContactList(void);
        void    printContact(Contact contact);
        Contact get_contact(int index);
};

#endif