/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:49:16 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/07 20:57:10 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include "ClapTrap.h"

FragTrap::FragTrap(): ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}


FragTrap::FragTrap(std::string &name)
{
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & other): ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap Assignment operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap requests high-fives" << std::endl;
}
