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
	a.takeDamage(12);
	a.takeDamage(1);
	a.beRepaired(8);
	a.takeDamage(7);
	a.beRepaired(9);
	for (int i = 0; i < 10; i++)
	{
		a.beRepaired(1);
	}
	a.attack("enamy");
}
