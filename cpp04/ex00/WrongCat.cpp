/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:30:09 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/10 01:30:36 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = other;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}
void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}
