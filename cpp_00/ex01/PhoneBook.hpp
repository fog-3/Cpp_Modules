/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:05:15 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/16 11:05:16 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int     _index;
        std::string formatField(const std::string &str) const;
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void        addContact(void);
        void        displayContactList(void);
        void        printContact(Contact contact);
};

#endif