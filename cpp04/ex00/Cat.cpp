/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:32:28 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/08 20:33:34 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}
