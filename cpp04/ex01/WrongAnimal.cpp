/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:27:06 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/10 01:28:47 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = other;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return this->type;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}