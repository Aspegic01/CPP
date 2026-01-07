/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:19:13 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/07 20:40:59 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap{
public:
    ScavTrap();
    ScavTrap(std::string &name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();
    void    attack(const std::string &target);
    void    guardGate();

};

#endif
