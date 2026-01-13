/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:10:57 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/06 17:11:13 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
int main(){
	ClapTrap a("3silla");
	ScavTrap b("kho 3sila");
	FragTrap c("fraggy");
	c.attack("enemy frag");
	c.highFivesGuys();
	for (int i = 0; i < 5; i++)
	{
		b.attack("enemy");
	}
	b.guardGate();
	b.takeDamage(6);
	b.beRepaired(1);
	a.takeDamage(12);
	a.takeDamage(1);
	a.beRepaired(8);
	a.takeDamage(7);
	a.beRepaired(9);
	for (int i = 0; i < 10; i++)
	{
		a.beRepaired(1);
	}
	a.attack("enemy");
}
