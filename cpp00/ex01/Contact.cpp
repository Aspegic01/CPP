/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:32:13 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/09/06 10:32:16 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string& str)
{
    firstName = str;
}

void Contact::setLastName(const std::string& str)
{
    lastName = str;
}

void Contact::setNickname(const std::string& str)
{
    nickname = str;
}

void Contact::setPhoneNumber(const std::string& str)
{
    phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string& str)
{
    darkestSecret = str;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

bool Contact::isEmpty() const
{
    return (firstName.empty() || lastName.empty() || nickname.empty() || 
            phoneNumber.empty() || darkestSecret.empty());
}
