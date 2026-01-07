/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:41:04 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/07 20:57:17 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

ScavTrap::ScavTrap(): ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string &name)
{
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other): ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ScavTrap Assignment operator called" << std::endl;
    return *this;
}

void    ScavTrap::attack(const std::string &target)
{

    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " has no energy or hit points left to attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

