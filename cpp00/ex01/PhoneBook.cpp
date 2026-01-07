/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:31:58 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/09/25 14:04:11 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(){
    currentIndex = 0;
    totalContacts = 0;
}

PhoneBook::~PhoneBook(){}

void PhoneBook::addContact(const Contact &contact)
{
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

std::string PhoneBook::truncateString(const std::string &str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width - 1) + ".";
    return str;
}

void PhoneBook::displayContacts()
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index)
{
    if (index < 0 || index >= totalContacts)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getTotalContacts()
{
    return totalContacts;
}
