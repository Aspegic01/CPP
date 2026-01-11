/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:49:16 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/11 15:00:06 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(std::string ideas[]){
	std::cout << "Brain parameterized constructor called\n";
	for (int i = 0;i<100;i++){
		this->ideas[i] = ideas[i];}
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}
Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}
Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
