/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:33:49 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/08 20:45:21 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include "Brain.h"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
}
Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}
void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
