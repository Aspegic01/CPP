/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:31:46 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/09/06 10:59:10 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

std::string getInput(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

Contact createContact()
{
    Contact contact;
    std::string input;

    while (true) {
        input = getInput("Enter first name: ");
        if (!input.empty())
            break;
    }
    contact.setFirstName(input);
    while (true) {
        input = getInput("Enter last name: ");
        if (!input.empty())
            break;
    }
    contact.setLastName(input);
    while (true) {
        input = getInput("Enter nickname: ");
        if (!input.empty())
            break;
    }
    contact.setNickname(input);
    while (true) {
        input = getInput("Enter phone number: ");
        if (!input.empty())
            break;
    }
    contact.setPhoneNumber(input);
    while (true) {
        input = getInput("Enter darkest secret: ");
        if (!input.empty())
            break;
    }
    contact.setDarkestSecret(input);

    return contact;
}

void searchContacts(PhoneBook& phoneBook)
{
    if (phoneBook.getTotalContacts() == 0)
    {
        std::cout << "No contacts available!" << std::endl;
        return;
    }
    
    phoneBook.displayContacts();
    
    std::string input;
    int index;
    
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, input);
    
    bool isValid = true;
    index = 0;
    
    if (input.empty())
        isValid = false;
    
    for (size_t i = 0; i < input.length() && isValid; i++)
    {
        if (input[i] < '0' || input[i] > '9')
            isValid = false;
        else
            index = index * 10 + (input[i] - '0');
    }
    
    if (isValid)
        phoneBook.displayContactDetails(index);
    else
        std::cout << "Invalid index!" << std::endl;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to your awesome phonebook!" << std::endl;
    
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (command == "ADD")
        {
            Contact newContact = createContact();
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH")
        {
            searchContacts(phoneBook);
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command! Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}
