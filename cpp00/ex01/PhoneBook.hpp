/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:31:53 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/09/06 10:31:55 by mlabrirh         ###   ########.fr       */
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
    
    std::string truncateString(const std::string& str, size_t width) const;

public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
    int getTotalContacts() const;
};

#endif
