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

int main(){
	ClapTrap a("3silla");
	for (int i = 0; i < 5; i++)
	{
		a.attack("enemy");
	}
	a.takeDamage(6);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.attack("enemy");
	a.attack("enemy");
	a.attack("enemy");
}
