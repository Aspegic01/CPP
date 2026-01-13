/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:11:29 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/06 17:11:50 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string const & name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "ClapTrap  Copy constructed called" << std::endl;
}
ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap  Assignment operator called" << std::endl;
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructed called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap  has no energy points left to attack." << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is now destroyed!" << std::endl;
        return;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage, remaining hit points: " << hitPoints << "." << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap has no energy or hit points left to repaired" << std::endl; 
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " points, total hit points: " << hitPoints << "." << std::endl;
}
