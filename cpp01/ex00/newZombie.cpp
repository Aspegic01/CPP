/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:03:39 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/11/26 09:32:54 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string Zombie_name){
	_name = Zombie_name;
}

Zombie::~Zombie(void){
	std::cout << "Zombie " << _name << " is dead x_x" << std::endl;
}

void Zombie::announce(){
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
