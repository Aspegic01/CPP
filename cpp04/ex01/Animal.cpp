/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:20:55 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/08 20:40:54 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal(){
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type):type(type){
	std::cout << "Animal parametrized constructor called" << std::endl;
}

Animal::Animal(const Animal &other){
	std::cout << "Animal copy constructor called\n";
	type = other.type;
}

Animal& Animal::operator=(const Animal &other){
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType()const
{
	return type;
}

void Animal::makeSound()const
{
	std::cout << "yeehaw" << std::endl;
}


