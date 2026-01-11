/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:14:10 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/08 20:41:46 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define	ANIMAL_H
#include <string>
#include <iostream>

class Animal
{
	protected:
	std::string type;

	public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	Animal& operator=(const Animal &other);
	virtual ~Animal();
	std::string getType() const;
	virtual void makeSound() const =0;
};
#endif
