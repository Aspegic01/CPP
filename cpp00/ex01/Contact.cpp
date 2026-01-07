/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:32:13 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/09/25 14:22:21 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string &str)
{
    firstName = str;
}

void Contact::setLastName(const std::string &str)
{
    lastName = str;
}

void Contact::setNickname(const std::string &str)
{
    nickname = str;
}

void Contact::setPhoneNumber(const std::string &str)
{
    phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string &str)
{
    darkestSecret = str;
}

std::string Contact::getFirstName()
{
    return firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

std::string Contact::getNickname()
{
    return nickname;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}

bool Contact::isEmpty()
{
    return (firstName.empty() || lastName.empty() || nickname.empty() || 
            phoneNumber.empty() || darkestSecret.empty());
}
