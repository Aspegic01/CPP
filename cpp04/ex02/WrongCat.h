/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:29:50 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/10 01:30:02 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H
#include "WrongAnimal.h"
class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat();
	void makeSound() const;
};
#endif
