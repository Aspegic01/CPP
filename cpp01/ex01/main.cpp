/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:48:27 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/11/26 10:18:24 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 6;
    Zombie* horde = zombieHorde(N, "ZombieHorde");
    if(!horde)
        return std::cout << "Failed to create Zombie horde" << std::endl, 1;
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}