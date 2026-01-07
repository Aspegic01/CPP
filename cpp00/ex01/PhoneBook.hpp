/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:31:53 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/09/25 10:28:39 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;
    
public:
    
    PhoneBook ();
    ~PhoneBook();
    std::string truncateString(const std::string &str, size_t width);
    void addContact(const Contact &contact);
    void displayContacts();
    void displayContactDetails(int index);
    int getTotalContacts();
};

#endif
