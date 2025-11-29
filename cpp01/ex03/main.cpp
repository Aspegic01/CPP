/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:14:50 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/11/28 18:26:47 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
// {
// Weapon club = Weapon("crude spiked club");
// HumanB jim("mouad");
// jim.setWeapon(club);
// jim.attack();
// club.setType("some other type of club");
// jim.attack();
// }
return 0;
}

// int main()
// {
// Weapon club = Weapon("crude spiked club");
// HumanA bob("Bob", club);
// bob.attack();
// club.setType("some other type of club");
// bob.attack();
// return 0;
// }