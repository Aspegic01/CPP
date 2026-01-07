/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:11:23 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/06 17:11:27 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <string>
#include <iostream>
class ClapTrap
{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
public:
    ClapTrap();
    ClapTrap(std::string const & name);
    ClapTrap(ClapTrap const & other);
    ~ClapTrap();
    ClapTrap & operator=(ClapTrap const & other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif