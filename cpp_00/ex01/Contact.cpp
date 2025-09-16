/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:04:55 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/16 11:04:56 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::getFirstName(void) const
{
    return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
    return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
    return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
    return (this->_darkestSecret);
}

void Contact::setFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}
