/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:39:25 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/11/26 09:28:06 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	Zombie* z = newZombie("3sila");
	if (!z)
		return std::cout << "Failed to create Zombie" << std::endl, 1;
	z->announce();
	delete z;
	randomChump("Kho 3ssila");
}
