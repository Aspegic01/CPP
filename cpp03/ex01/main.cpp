/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:10:57 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/13 20:00:54 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

int main(){
	ScavTrap b("kho 3sila");
	for (int i = 0; i < 5; i++)
	{
		b.attack("enemy");
	}
	b.guardGate();
	b.takeDamage(6);
	b.beRepaired(1);
}
